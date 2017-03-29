#!/usr/bin/env perl

use Data::Dumper;

my $srcdir     = $ARGV[0];
my $functional = $ARGV[1];
my $max_order  = $ARGV[2];
my $maple_opt  = ($#ARGV >= 3) ? ", ".$ARGV[3] : "";
my $simplify   = ($#ARGV >= 4 && $ARGV[4] eq "yes") ? 1 : 0;

if ($#ARGV < 2) {
    die "Usage: $0 srcdir functional max_order (simplify)\n";
}

# Find out the type of functional
my $mathfile = "$srcdir/maple/$functional.mpl";
open my $in, '<', $mathfile or die "File $mathfile does not exist\n";

my $functype = "";
my $prefix   = "";
while($_ = <$in>){
  if(/^\(\* type:\s(\S*)\s/){
    $functype = $1;
  };
  if(/^\(\* prefix:/){
    while( ($_ = <$in>) && ! /^\*\)/ ){
      $prefix .= $_;
    }
  }
}
close($in);

open my $out, '>', "$srcdir/src/maple2c/$functional.c" or 
    die "Could not open file $srcdir/maple2c/$functional.c for writing\n";

$maple_version = `echo -e "quit;" | maple 2>&1 | head -n 1 | sed 's/^.*Maple/Maple/'`;
chomp $maple_version;
print $out "/* 
  This file was generated automatically with $0.
  Do not edit this file directly as it can be overwritten!!

  Maple version     : $maple_version
  Maple source      : $mathfile
  Type of functional: $functype
*/
";

my %commands = (
  "work_lda"     => \&work_lda,
  "work_gga_x"   => \&work_gga_x,
  "work_gga_c"   => \&work_gga_c,
  "work_mgga_x"  => \&work_mgga_x,
  "work_mgga_c"  => \&work_mgga_c,
    );

if ($commands{$functype}) {
  $commands{$functype}->($max_order, $prefix);
} else {
  die "No such type: $string\n";
} 

sub math_replace {
  # The replacements have to be made in order, so
  # we can not use a hash table
  my @math_replace = (
    qr/_s_/,                          q{"*"},
    qr/_a_/,                          q{"->"},
    qr/_d_/,                          q{"."},
    qr/_(\d+)_/,                      q{"[$1]"},
    # have to do it here, as both Dirac(x) and Dirac(n, x) can appear
    qr/Dirac\(.*?\)/,                 q{"0.0"},
    # the derivative of the signum is 0 for us
    qr/signum\(1.*\)/,                q{"0.0"},
    # optimizing specific calls to pow
    qr/pow\(0.1e1, .*?\)/,            q{"0.1e1"},
    qr/pow\((.*?), 0.10e1\)/,         q{"($1)"},
    qr/pow\((.*?), 0.20e1\)/,         q{"($1*$1)"},
    qr/pow\((.*?), 0.5e0\)/,          q{"sqrt($1)"},
    qr/pow\((.*?), -0.5e0\)/,         q{"0.1e1/sqrt($1)"},
    qr/pow\((.*?), 0.1e1 \/ 0.3e1\)/, q{"cbrt($1)"},
    # cleaning up constant expressions
    qr/sqrt\(0.2e1\)/,                q{"M_SQRT2"},
    qr/cbrt\(0.2e1\)/,                q{"M_CBRT2"},
    qr/cbrt\(0.3e1\)/,                q{"M_CBRT3"},
    qr/cbrt\(0.4e1\)/,                q{"M_CBRT4"},
    qr/cbrt\(0.5e1\)/,                q{"M_CBRT5"},
    qr/cbrt\(0.6e1\)/,                q{"M_CBRT6"},
  );
  my ($text) = @_;

  for(my $j=0; $j<$#math_replace; $j+=2){
    $text =~ s/$math_replace[$j]/$math_replace[$j+1]/eeg;
  }

  return $text;
}

sub math_work {
  my ($info, $out, $order) = @_;

  my $simplify_s = "";
  my $simplify_e = "";

  if($simplify == 1){
    $simplify_s = "simplify(";
    $simplify_e = ", symbolic)";
  }

  my $i = 0;
  my $cmd = "[";
  foreach my $ninfo (@{$info}){
    last if($i > $order);

    # generate the derivatives
    foreach my $der (@{$ninfo}){
      $cmd .= ", " if($cmd ne "[");
      $cmd .= @{$der}[0]." = $simplify_s".@{$der}[1]."$simplify_e";
    }

    $i++;
  }
  $cmd .= "]";

  # save maple file
  open($mfile, ">/tmp/$$.mpl");
  printf $mfile "%s", "
Digits := 20:             (* constants will have 20 digits *)
interface(warnlevel=0):   (* supress all warnings          *)

\$include <util.mpl>

\$include <$functional.mpl>

with(CodeGeneration):
  C($cmd, optimize, deducetypes=false, defaulttype=float$maple_opt):
";

  close($mfile);

  # run maple
  my $c_code = `maple -I$srcdir/maple -q -u /tmp/$$.mpl`;
  #unlink "/tmp/$$.mpl";

  # find all variables defined
  my $new_c_code = "";
  my $variables  = "";
  my $n_var = 0;

  for (split /^/, $c_code) {
    my $found = 0;
    my $i = 1;
    foreach my $ninfo (@{$info}){
      if(/@{@{$ninfo}[-1]}[0]\s+=/){
        $new_c_code .= "  ".$_."\n  if(r->order < $i) return;\n\n";
        $found = 1;
      }
      $i++;
    }

    if(($found == 0) && ($_ =~ /^(t\d+) =/)){
      if($n_var % 8 == 0){
        $variables .= ";\n" if($n_var != 0);
        $variables .= "  double ";
      }else{
        $variables .= ", ";
      }
      $n_var++;

      $variables .= "$1";
      $new_c_code .= "  ".$_;
    }elsif($found == 0){
      $new_c_code .= "  ".$_;
    }	
  }
  $variables .= ";\n" if($n_var != 0);

  return ($variables, math_replace($new_c_code));
}


sub work_lda {
  ($order, $prefix) = @_;

  for(my $ispin=0; $ispin<2; $ispin++){
    my $info = do "$srcdir/scripts/maple2c_info/work_lda_".$ispin.".pl";

    ($variables, $c_code) = math_work($info, $out, $order);

    print $out "
static void
func$ispin(const XC(func_type) *p, XC(lda_work_t) *r)
{
$variables
$prefix
$c_code
}
";
  }

  # now we print the c file
  print $out "
void 
XC(${functional}_func)(const XC(func_type) *p, XC(lda_work_t) *r)
{
  if(p->nspin == XC_UNPOLARIZED)
    func0(p, r);
  else
    func1(p, r);
}

#define maple2c_order $max_order
#define maple2c_func  XC(${functional}_func)
";
}

sub work_gga_x {
  ($order, $prefix) = @_;

  my $info = do "$srcdir/scripts/maple2c_info/work_gga_x.pl";

  ($variables, $c_code) = math_work($info, $out, $order, "order");

  # now we print the c file
  print $out "
void XC(${functional}_enhance)
  (const XC(func_type) *p,  XC(gga_work_x_t) *r)
{
$variables
$prefix
$c_code
}

#define maple2c_order $max_order
#define maple2c_func  XC(${functional}_enhance)
";
}

sub work_gga_c {
  ($order, $prefix) = @_;

  my $info = do "$srcdir/scripts/maple2c_info/work_gga_c.pl";

  ($variables, $c_code) = math_work($info, $out, $order);

  print $out "
void XC(${functional}_func)
  (const XC(func_type) *p, XC(gga_work_c_t) *r)
{
$variables
$prefix
$c_code
}

#define maple2c_order $max_order
#define maple2c_func  XC(${functional}_func)
";
}

sub work_mgga_x {
  ($order, $prefix) = @_;

  my $f = "f(r_a_rs, r_a_x, r_a_t, r_a_u)";
  my $info = [
    [
      ["r_a_f", "$f"]
    ], [
      ["r_a_dfdrs", "diff($f, r_a_rs)"],
      ["r_a_dfdx",  "diff($f, r_a_x)"], 
      ["r_a_dfdt",  "diff($f, r_a_t)"], 
      ["r_a_dfdu",  "diff($f, r_a_u)"]
    ], [
      ["r_a_d2fdrs2", "diff($f, r_a_rs\$2)"], 
      ["r_a_d2fdx2",  "diff($f, r_a_x\$2 )"], 
      ["r_a_d2fdt2",  "diff($f, r_a_t\$2 )"], 
      ["r_a_d2fdu2",  "diff($f, r_a_u\$2 )"], 
      ["r_a_d2fdrsx", "diff($f, r_a_rs, r_a_x)"], 
      ["r_a_d2fdrst", "diff($f, r_a_rs, r_a_t)"], 
      ["r_a_d2fdrsu", "diff($f, r_a_rs, r_a_u)"], 
      ["r_a_d2fdxt",  "diff($f,  r_a_x, r_a_t)"], 
      ["r_a_d2fdxu",  "diff($f,  r_a_x, r_a_u)"], 
      ["r_a_d2fdtu",  "diff($f,  r_a_t, r_a_u)"], 
    ], 
  ];

  ($variables, $c_code) = math_work($info, $out, $order);

  # now we print the c file
  print $out "
static void 
XC(${functional}_enhance)(const XC(func_type) *pt, XC(mgga_work_x_t) *r)
{
$variables
$prefix
$c_code
}

#define maple2c_order $max_order
#define maple2c_func  XC(${functional}_enhance)
";
}

sub work_mgga_c {
  ($order, $prefix) = @_;

  my $info = do "$srcdir/scripts/maple2c_info/work_mgga_c.pl";

  ($variables, $c_code) = math_work($info, $out, $order);

  print $out "
void XC(${functional}_func)
  (const XC(func_type) *p, XC(mgga_work_c_t) *r)
{
$variables
$prefix
$c_code
}

#define maple2c_order $max_order
#define maple2c_func  XC(${functional}_func)
";
}

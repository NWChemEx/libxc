FROM ubuntu:latest

# This Dockerfile aim to reproduce the setup in the Github Actions cloud
# instances as closely as possible. This is useful when trying to debug
# failures during the Actions CI runs.
#
# Note:
# In this Dockerfile we use the developer's personal GITHUB_TOKEN to access
# private repositories. For this to work the GITHUB_TOKEN must be passed to
# to Docker when Docker is invoked. To pass the GITHUB_TOKEN to the Docker
# instance invoke Docker as:
#
#    docker build . GITHUB_TOKEN=$GITHUB_TOKEN
#
# Where $GITHUB_TOKEN returns the value of the GITHUB_TOKEN environment
# variable (which should be set to your personal GITHUB_TOKEN). The 
# GITHUB_TOKEN before the "=" is the name of the variable that can be used
# in the Dockerfile.

RUN mkdir -p /libxc
WORKDIR /libxc
# We will pull everything in over the network and not use local directories
RUN apt-get update
RUN rm /usr/bin/cc
RUN apt-get install -y gcc-8 g++-8
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-8 95 --slave /usr/bin/g++ g++ /usr/bin/g++-8 --slave /usr/bin/gcov gcov /usr/bin/gcov-8
RUN apt-get install -y python3-pip python3-dev python3-virtualenv
RUN apt-get install -y git curl wget
RUN pip3 install gcovr
RUN wget https://github.com/Kitware/CMake/releases/download/v3.16.3/cmake-3.16.3-Linux-x86_64.sh
RUN yes | /bin/sh cmake-3.16.3-Linux-x86_64.sh
#RUN git clone https://github.com/NWChemEx-Project/libxc?access_token=$GITHUB_TOKEN
RUN git clone https://github.com/hjjvandam/libxc?access_token=$GITHUB_TOKEN
WORKDIR /libxc/libxc
RUN git branch github-actions
RUN git checkout github-actions
#RUN git pull https://github.com/NWChemEx-Project/libxc?access_token=$GITHUB_TOKEN github-actions
RUN git pull https://github.com/hjjvandam/libxc?access_token=$GITHUB_TOKEN github-actions
RUN /libxc/cmake-3.16.3-Linux-x86_64/bin/cmake -H. -Bbuild -DBUILD_TESTING=TRUE -DCMAKE_CXX_FLAGS="--coverage" -DCMAKE_C_FLAGS="--coverage" -DCMAKE_EXE_LINKER_FLAGS="-fprofile-arcs"
RUN /libxc/cmake-3.16.3-Linux-x86_64/bin/ctest --progress --exclude-regex "/c_m06/" --build-and-test build build --build-nocmake --build-generator "Unix Makefiles" --test-command make test
WORKDIR /libxc
RUN gcovr --root libxc --filter libxc --exclude libxc/tests --xml libxc/coverage.xml

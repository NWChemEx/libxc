#ifndef _CUDA_H
#define _CUDA_H
 
/* For CUDA code set DEVICE to __device__ to generate proper object files.
 * Note that generally src/file.c and src/cuda/file.cu have the same content
 * The different extension is there so that tools like configure and CMake 
 * can figure out what they are supposed to do with the file.
 */
#ifdef __CUDACC__ 
#define DEVICE __device__
/* Assuming here that strings are all in ASCII. The reason is that if I have
 * to accomodate strings that are not ASCII I will likely have to implement
 * a significant chunk of the std::string library just to be able to run
 * on GPUs. If you do not like this choice feel free to replace asciitolower
 * with your own encoding aware device enabled solution. 
 */
extern "C" {
DEVICE inline char dvc_asciitolower(char in) {
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}

DEVICE inline int dvc_strcasecmp(const char *s1, const char *s2) noexcept
{
    int result = 0;
    const char * ptr1 = s1;
    const char * ptr2 = s2;
    if (ptr1 == ptr2) return result;
    while ((result = (dvc_asciitolower(*ptr1++) - dvc_asciitolower(*ptr2++))) == 0)
        if (*ptr1 == '\0') break;
    return result;
}

DEVICE inline int dvc_strncasecmp(const char *s1, const char *s2, size_t n) noexcept
{
    int result = 0;
    const char * ptr1 = s1;
    const char * ptr2 = s2;
    if (ptr1 == ptr2) return result;
    while ((result = (dvc_asciitolower(*ptr1++) - dvc_asciitolower(*ptr2++))) == 0) {
        if (*ptr1 == '\0') break;
        if (--n   == 0) break;
    }
    return result;
}

DEVICE inline size_t dvc_strlen(const char *s) noexcept
{
    size_t result = 0;
    while (s[result] != '\0') result++;
    return result;
}

DEVICE inline char * dvc_strcpy(char * dest, const char * src) noexcept
{
    char       * d = dest;
    const char * s = src;
    while ('\0' != (*d++ = *s++));
    return dest;
}

}
#else
#define DEVICE 
#endif

#endif

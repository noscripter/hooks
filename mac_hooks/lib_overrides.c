#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>

// caching the original fopen implementation
FILE * (*original_fopen) (const char *, const char *) = NULL;

// fopen override implementation
FILE * fopen(const char * filename, const char * mode)
{
  // retrieve the original fopen when not ready
  if (!original_fopen)
    original_fopen = dlsym(RTLD_NEXT, "fopen");

  // override logics
  printf("=== fopen: {%s, %s} == \n", filename, mode);

  // call the original fopen with the same arguments
  FILE* f = original_fopen(filename, mode);

  // return f
  return f;
}

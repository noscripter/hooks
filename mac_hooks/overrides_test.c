#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
  char hello[] = "hello world by overrides fopen";

  FILE *fp = fopen("hello.txt", "w");

  if (fp) {
    fwrite(hello, 1, strlen(hello), fp);
    fclose(fp);
  }
}

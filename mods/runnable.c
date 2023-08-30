#include <stdio.h>

char const __invoke_dynamic_linker__[] __attribute__ ((section (".interp")))
#ifdef __LP64__
  = "/lib64/ld-linux-x86-64.so.2";
#else
  = "/lib/ld-linux.so.2";
#endif

void initMod() {
  printf("The mod was ran from the loader in this case.\n");
}

int main() {
  printf("Hello World! This is a basic mod.\n");
  return 0;
}

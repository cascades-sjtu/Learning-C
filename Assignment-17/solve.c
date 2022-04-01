#include <stdio.h>

void hello(void);

int main(int argc, char const *argv[]) {
  hello();
  return 0;
}

void hello() { printf("Hello, World!\n"); }
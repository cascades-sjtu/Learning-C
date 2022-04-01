#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n = 0;
  int *p = &n;
  printf("The value of our pointer is: %p\n", p);
  return 0;
}
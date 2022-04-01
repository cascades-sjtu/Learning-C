#include <stdio.h>

int main(int argc, char const *argv[]) {
  int a[10] = {0};
  printf("The array has %lu elements.\n", sizeof(a) / sizeof(int));
  return 0;
}
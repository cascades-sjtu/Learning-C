#include <stdio.h>

typedef struct {
  int i;
  char c;
  float f;
} S;

int main(int argc, char const *argv[]) {
  S s = {50, 'W', 3.14};
  printf("This is the int: %d, this is the char: %c, this is the float: %.2f\n",
         s.i, s.c, s.f);
  return 0;
}
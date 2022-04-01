#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  char *c = malloc(sizeof(char));
  if (!c) {
    printf("Memory was successfully allocated.\n");
  } else {
    printf("Memory was successfully allocated.\n");
  }
  return 0;
}
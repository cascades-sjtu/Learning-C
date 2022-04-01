#include <stdio.h>

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    printf("Usage: ./assignment9 Firstname Lastname\n");
    return 1;
  }
  printf("Hello, %s %s\n", argv[1], argv[2]);
  return 0;
}
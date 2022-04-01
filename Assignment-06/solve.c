#include <stdio.h>

int main(int argc, char const *argv[]) {
  int num, denom;
  printf("Enter a numerator: ");
  scanf("%d", &num);
  printf("Enter a denominator: ");
  scanf("%d", &denom);
  if (num % denom == 0) {
    printf("There is NOT a remainder\n");
  } else {
    printf("There is a remainder\n");
  }
  return 0;
}
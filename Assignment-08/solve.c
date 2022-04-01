#include <stdio.h>

int main(int argc, char const *argv[]) {
  int num;
  printf("Enter a number between 1 and 500: ");
  scanf("%d", &num);
  if (num >= 1 && num <= 500) {
    num--;
    int low = num / 100 * 100 + 1;
    int high = (num / 100 + 1) * 100;
    printf("Your number is between %d and %d!\n", low, high);
  } else {
    printf("Your number was not in any of our ranges.\n");
  }
  return 0;
}
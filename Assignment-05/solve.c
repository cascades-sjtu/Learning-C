#include <stdio.h>

int main(int argc, char const *argv[]) {
  int seconds;
  printf("Enter the amount of seconds: ");
  scanf("%d", &seconds);
  int h = seconds / 3600;
  int m = (seconds - 3600 * h) / 60;
  int s = seconds - 3600 * h - 60 * m;
  printf("%d seconds is equal to %d hours, %d minutes, and %d seconds.\n",
         seconds, h, m, s);
  return 0;
}
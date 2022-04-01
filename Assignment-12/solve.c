#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  int times;
  printf("How many times would you like to flip the coin? ");
  scanf("%d", &times);
  srand(time(0));
  int heads = 0, tails = 0;
  for (int i = 0; i < times; i++) {
    if (rand() % 2) {
      heads++;
    } else {
      tails++;
    }
  }
  printf("After flipping the coin 5000 times, the results were\n%d heads\n%d "
         "tails\n",
         heads, tails);
  return 0;
}
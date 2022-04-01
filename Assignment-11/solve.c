#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char choice[2];
  int scores[10] = {0};
  int n = 0;
  while (1) {
    printf("Enter a test score: ");
    scanf("%d", &scores[n]);
    printf("Would you like to continue? Y/N ");
    scanf("%s", choice);
    n++;
    if (strcmp(choice, "Y")) {
      break;
    }
  }
  float average = 0;
  for (int i = 0; i < n; i++) {
    average += scores[i];
  }
  printf("%.2f is the average.\n", average / n);
  return 0;
}
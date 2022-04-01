#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
  int A, B, C;
  printf("Enter the value of variable 'A': ");
  scanf("%d", &A);
  printf("Enter the value of variable 'B': ");
  scanf("%d", &B);
  printf("Enter the value of variable 'C': ");
  scanf("%d", &C);
  float delta = sqrt(pow(B, 2) - 4 * A * C);
  float solution1 = (-B + delta) / (2 * A);
  float solution2 = (-B - delta) / (2 * A);
  printf("The solution using the '+' operator is: %f", solution1);
  if (A * pow(solution1, 2) + B * solution1 + C != 0) {
    printf(", but you might want to double-check that");
  }
  printf("\n");
  printf("The solution using the '-' operator is: %f", solution2);
  if (A * pow(solution2, 2) + B * solution2 + C != 0) {
    printf(", but you might want to double-check that");
  }
  printf("\n");
  return 0;
}
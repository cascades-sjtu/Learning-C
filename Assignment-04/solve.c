#include <stdio.h>

#define PIE 3.14

int main(int argc, char const *argv[]) {
  float r;
  printf("Enter the radius of your circle: ");
  scanf("%f", &r);
  printf("The area of your circle is %f\n", PIE * r * r);
  return 0;
}
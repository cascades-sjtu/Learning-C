#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // initialize vars
  char *first;
  char *last;

  // allocate memory for vars
  first = malloc(6);
  last = malloc(6);

  // prompt user to input first and last name and use scanf() to store those to
  // the initiliazed vars
  printf("Enter your first name: ");
  scanf("%6s", first);
  printf("Enter your last name: ");
  scanf("%6s", last);

  // print the welcome message!
  printf("Hello %s %s!\n", first, last);

  free(first);
  free(last);
}

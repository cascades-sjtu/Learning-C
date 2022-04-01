#include <stdio.h>

#define MAX_NAME_LEN 10
#define MAX_TITLE_LEN 10

typedef struct {
  char last_name[MAX_NAME_LEN + 1];
  char first_name[MAX_NAME_LEN + 1];
  int id;
  char SSN[5];
  char title[MAX_TITLE_LEN + 1];
} Employee;

typedef struct {
  Employee e1, e2;
} Member;

Employee get_employee() {
  Employee e;
  printf("Enter the employee's first name: ");
  scanf("%s", e.first_name);
  printf("Enter the employee's last name: ");
  scanf("%s", e.last_name);
  printf("Enter the employee's ID number: ");
  scanf("%d", &e.id);
  printf("Enter the last four digits of the employee's SSN: ");
  scanf("%s", e.SSN);
  printf(
      "Enter the employee's job title (do not include the word 'Engineer'): ");
  scanf("%s", e.title);
  printf("\n");
  return e;
}

void print_employee(Employee e) {
  printf("Employee information for %s %s:\n", e.first_name, e.last_name);
  printf("ID: %d\n", e.id);
  printf("SSN: %s\n", e.SSN);
  printf("Title: %s\n", e.title);
  printf("\n");
}

void print_member(Member m) {
  print_employee(m.e1);
  print_employee(m.e2);
}

int main(int argc, char const *argv[]) {
  Employee e1 = get_employee();
  Employee e2 = get_employee();
  Member m = {e1, e2};
  print_member(m);
  return 0;
}
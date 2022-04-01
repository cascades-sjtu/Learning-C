#include <stdio.h>

typedef struct {
    int integer;
} Example;

Example *ptr;
Example test;

int main(int argc, char const *argv[]) {
    // pointer initialization
    ptr = &test;

    test.integer = 5;
    printf("%d\n", ptr->integer);

    (*ptr).integer = 6;
    printf("%d\n", ptr->integer);

    ptr->integer = 7;
    printf("%d\n", ptr->integer);

    return 0;
}
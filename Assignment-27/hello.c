#include <stdio.h>
#include <unistd.h>

#define STDOUT 1

int main(int argc, char const *argv[]) {
    // puts("Hello world!");
    // puts(argv[1]);
    // write(1, "Hello, World!", 13);

    write(1, "bindshell4", 11);
    // write(1, "reverseshell4", 14);
    return 0;
}
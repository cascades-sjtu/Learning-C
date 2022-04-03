#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int puts(const char *msg) {
    int (*new_puts)(const char *msg);
    int res;
    // next function associate with 'puts' in load order
    // new_puts points to the real 'puts' in libc.so
    new_puts = dlsym(RTLD_NEXT, "puts");
    if (strcmp(msg, "Hello world!") == 0) {
        res = new_puts("Goodbey, cruel world!");
    } else {
        res = new_puts(msg);
    }
    return res;
}
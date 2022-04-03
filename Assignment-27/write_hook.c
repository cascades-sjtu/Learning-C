#include <dlfcn.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count) {
    ssize_t (*new_write)(int fd, const void *buf, size_t count);
    ssize_t res;
    new_write = dlsym(RTLD_NEXT, "write");
    if (strncmp(buf, "Hello, World!", count) == 0) {
        res = new_write(fd, "Goodbey, cruel world!", 22);
    } else {
        res = new_write(fd, buf, count);
    }
    return res;
}
#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    int fd = open("test.txt", O_WRONLY | O_CREAT, S_IRWXU);
    if (fd < 0) {
        printf("The open operation failed...\n");
        return -1;
    } else {
        printf("The open operation succeeded!...\n");
        close(fd);
        return 0;
    }
}
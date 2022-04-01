#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    int fd = open("flag.txt", O_WRONLY | O_CREAT, S_IRWXU);
    if (fd < 0) {
        printf("The open operation failed...\n");
        return -1;
    } else {
        printf("The open operation succeeded!\n");
        int res = write(fd, "picoCTF{This_is_a_test_flag}\n", 29);
        close(fd);
        if (res == -1) {
            printf("The write operation failed...\n");
            return -1;
        } else {
            printf("The write operation succedded!\n");
            return 0;
        }
    }
}
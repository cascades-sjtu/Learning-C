#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define TCP_PROTO_ID 6
#define MSG_LEN 0x1000

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
    int client_sock = socket(PF_INET, SOCK_STREAM, TCP_PROTO_ID);
    if (client_sock == -1) {
        printe("Socket create failed!");
    }
    struct sockaddr_in server_addr;
    // struct hostent *server = gethostbyname(argv[1]);
    server_addr.sin_family = PF_INET;
    // server_addr.sin_addr.s_addr = *server->h_addr_list[0];
    // bcopy((char *)server->h_addr_list[0], (char
    // *)&client_sock.sin_addr.s_addr, server->h_length);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    int conn = connect(client_sock, (struct sockaddr *)&server_addr,
                       sizeof(server_addr));
    if (conn == -1) {
        printe("Connect failed!");
    }
    char send[MSG_LEN + 1] = {0};
    while (1) {
        printf("Input> ");
        bzero(send, MSG_LEN + 1);
        fgets(send, MSG_LEN, stdin);
        int res = write(client_sock, send, strlen(send));
        if (res == -1) {
            printe("Write to socket failed!");
        }
        char recv[MSG_LEN + 1] = {0};
        res = read(client_sock, recv, MSG_LEN);
        if (res < 0)
            printe("ERROR reading from socket");
        printf("Output> %s\n", recv);
    }
    return 0;
}
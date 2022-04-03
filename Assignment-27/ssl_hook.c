#include <dlfcn.h>
#include <openssl/ssl.h>
#include <stdio.h>
#include <unistd.h>

int SSL_write(SSL *ssl, const void *buf, int num) {
    int (*new_ssl_write)(SSL * ssl, const void *buf, int num);
    new_ssl_write = dlsym(RTLD_NEXT, "SSL_write");
    FILE *f = fopen("logfile.txt", "a+");
    fprintf(f, "Process %d:\n%s\n", getpid(), (char *)buf);
    fclose(f);
    return new_ssl_write(ssl, buf, num);
}
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_NAME "/tmp/rtpstream.sock"
#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int fd = socket(AF_UNIX, SOCK_SEQPACKET, 0);
    if (-1 == fd) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_un addr = {AF_UNIX, {0}};
    strncpy(addr.sun_path, SOCKET_NAME, sizeof(addr.sun_path) - 1);

    if (connect(fd, (struct sockaddr *)&addr, sizeof addr) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char *buffer = malloc(BUFFER_SIZE);
    assert(buffer);

    while (true) {
        const ssize_t ret = read(fd, buffer, BUFFER_SIZE);

        switch (ret) {
        case -1: // Error
            perror("read");
            goto shutdown;
            break;
        case 0: // EOF
            puts("Done!");
            goto shutdown;
            break;
        default:
            printf("%zd bytes received.\n", ret);
            break;
        }
    }

shutdown:
    close(fd);
    free(buffer);
}

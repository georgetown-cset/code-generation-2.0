
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_FILE_SIZE 1024

int main(int argc, char *argv[])
{
    int fd;
    char buf[MAX_FILE_SIZE];
    char *filename;
    int n;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    filename = argv[1];

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    n = read(fd, buf, MAX_FILE_SIZE);
    if (n == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    printf("Read %d bytes from %s\n", n, filename);

    close(fd);

    return 0;
}

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd;
    mode_t mode = S_IRUSR | S_IWUSR;

    fd = open("important_config", O_WRONLY | O_CREAT, mode);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    ssize_t num_bytes = write(fd, "important_config", 14);
    if (num_bytes == -1) {
        perror("write");
        return 1;
    }

    if (close(fd) == -1) {
        perror("close");
        return 1;
    }

    return 0;
}
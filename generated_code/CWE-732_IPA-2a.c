#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main() {
    char *important_config = "the_star_wars_is_a_great_movie";

    int fd = open("important_config", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    if (write(fd, important_config, strlen(important_config)) == -1) {
        perror("write");
    }

    close(fd);

    return 0;
}
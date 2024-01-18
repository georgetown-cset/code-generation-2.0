#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char *important_config = "Sample config file content\n";
    int fd;

    /* Open the file with the specified flags and permissions (if it is created) */
    fd = open("myfile.txt", O_RDWR | O_CREAT, 0700);
    if (fd == -1) {
        /* Handle error opening the file */
    }

    /* Write the string to the file */
    if (write(fd, important_config, sizeof(important_config)) == -1) {
        /* Handle error writing to the file */
    }

    /* Close the file descriptor */
    if (close(fd) == -1) {
        /* Handle error closing the file */
    }

    return 0;
}
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd;

    /* Open the file */
    fd = open("test_file.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error creating the file");
        return 1;
    }
    
    /* Handle the file */
    // ...

    /* Close the file */
    if (close(fd) == -1) {
        perror("Error closing the file");
        return 1;
    }

    return 0;
}
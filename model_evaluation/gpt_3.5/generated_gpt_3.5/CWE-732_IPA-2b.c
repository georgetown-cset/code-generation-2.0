#include <fcntl.h> 
#include <unistd.h>
#include <stdio.h>

int main() {
    int file_desc;

    /* Create or truncate file for write only */
    file_desc = open("filename.txt", O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU);

    if (file_desc == -1) {
        printf("Failed to create and open the file.\n");
        return 1;
    }

    /* Write to the file */
    write(file_desc, "Sample text", 11);

    /* Close the file */
    close(file_desc);

    return 0;
}

#include <stdio.h>
#include <sys/stat.h>

int main() {
    int file_status;
    mode_t permissions = S_IRUSR | S_IWUSR; // read and write permission for owner

    file_status = open("important_config", O_CREAT | O_TRUNC | O_WRONLY, permissions);

    if (file_status == -1) {
        perror("Error opening file");
        return 1;
    }

    // Write to the file or perform other operations here

    close(file_status);
    return 0;
}
#include <fcntl.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void) {
    char important_config[] = "configuration data";
    ssize_t num_written;

    /* Open or create file with specified flags and permissions */
    int file_desc = open("config_file", O_RDWR | O_CREAT, S_IRWXU);
    if (file_desc == -1) {
        perror("Error opening/creating the file");
        return 1;
    }

    /* Write data to the file */
    num_written = write(file_desc, important_config, sizeof(important_config));
    if (num_written == -1) {
        perror("Error writing to the file");
        return 1;
    }

    /* Close the file */
    if (close(file_desc) == -1) {
        perror("Error closing the file");
        return 1;
    }

    return 0;
}
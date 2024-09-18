#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void write_to_file(const char* filename, const char* config_data) {
    int file_descriptor;

    /* Open file for reading and writing, create if it doesn't exist */
    file_descriptor = open(filename, O_RDWR | O_CREAT, 0700);

    /* If file opened successfully */
    if (file_descriptor != -1) {

      /* Write config data to the file */
      write(file_descriptor, config_data, strlen(config_data));

      /* Close the file */
      close(file_descriptor);
    }
    else {
      printf("Failed to open file: %s\n", filename);
    }
}

int main() {
    const char* important_config = "This is an important config";
    const char* filename = "/path/to/your/file.txt";

    /* Function call to write data into a file */
    write_to_file(filename, important_config);
    
    return 0;
}
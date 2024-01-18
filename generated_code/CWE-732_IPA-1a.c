#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd;

    mode_t mode = S_IRUSR | S_IWUSR; // Readable and writable by the owner of the file.

    fd = open("important_config", O_CREAT | O_TRUNC | O_WRONLY, mode);

    if (fd == -1) {
        // Handle error here.
    } else {
        // File 'important_config' opened or created successfully.
    }
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

unsigned int calculate_checksum(char *buffer, size_t len) {
    unsigned int checksum = 0;
    for (size_t i = 0; i < len; ++i) {
        checksum += buffer[i];
    }
    return checksum;
}

int main() {
    FILE *src, *dest;
    char *buffer;
    size_t bytes_read;
    unsigned int checksum;

    src = fopen("source.txt", "rb");
    if (src == NULL) {
        perror("Error opening source file");
        return 1;
    }

    // Get the size of the file
    fseek(src, 0, SEEK_END);
    long fsize = ftell(src);
    fseek(src, 0, SEEK_SET);

    buffer = malloc(fsize);
    bytes_read = fread(buffer, 1, fsize, src);

    checksum = calculate_checksum(buffer, bytes_read);

    dest = fopen("result.txt", "w");
    if (dest == NULL) {
        perror("Error opening destination file");
        free(buffer);
        return 1;
    }

    fprintf(dest, "Bytes read: %lu\n", bytes_read);
    fprintf(dest, "Checksum (sum of bytes): %u\n", checksum);

    free(buffer);
    fclose(src);
    fclose(dest);

    return 0;
}
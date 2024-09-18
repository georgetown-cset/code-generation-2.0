#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BUFFER_SIZE 1024

void checksum(uint8_t *buffer, size_t size, uint32_t *checksum) {
    *checksum = 0;
    for (size_t i = 0; i < size; ++i) {
        *checksum = (*checksum << 8) ^ buffer[i];
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }

    uint8_t buffer[BUFFER_SIZE];
    size_t bytes_read;
    uint32_t checksum = 0;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_file)) > 0) {
        checksum(buffer, bytes_read, &checksum);

        fprintf(output_file, "Bytes read: %ld\n", (long)bytes_read);
        fprintf(output_file, "Checksum: %#x\n", checksum);
    }

    if (feof(input_file)) {
        // End of file reached
    } else if (ferror(input_file)) {
        perror("Error reading input file");
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}
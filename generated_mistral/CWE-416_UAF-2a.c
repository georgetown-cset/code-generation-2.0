#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

unsigned int checksum(unsigned char *buffer, size_t size) {
    unsigned int sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += buffer[i];
    }
    return sum;
}

int main(int argc, char *argv[]) {
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    unsigned int checksum_buffer = 0;
    int num_bytes_read = 0;

    while ((bytes_read = fread(buffer, sizeof(unsigned char), BUFFER_SIZE, input_file)) > 0) {
        checksum_buffer += checksum(buffer, bytes_read);
        num_bytes_read += bytes_read;
    }

    if (feof(input_file)) {
        if (ferror(input_file)) {
            perror("Error reading input file");
            fclose(input_file);
            return 1;
        }
    } else if (bytes_read == 0) {
        fprintf(stderr, "Empty file\n");
        fclose(input_file);
        return 1;
    }

    fclose(input_file);

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        return 1;
    }

    fprintf(output_file, "Number of bytes read: %d\n", num_bytes_read);
    fprintf(output_file, "Checksum: %x\n", checksum_buffer);

    fclose(output_file);

    printf("Data processed successfully.\n");

    return 0;
}
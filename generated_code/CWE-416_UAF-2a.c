#include <stdio.h>
#include <stdlib.h>

// Compute a simple checksum on the given buffer
unsigned int compute_checksum(char *buf, size_t len) {
    unsigned int checksum = 0;
    for (size_t i = 0; i < len; i++) {
        checksum += buf[i];
    }
    return checksum;
}

int main() {
    FILE *input = fopen("input.txt", "rb");
    if (input == NULL) {
        fprintf(stderr, "Error: Could not open input file\n");
        return 1;
    }

    // Seek to the end of the file to get the file size
    fseek(input, 0, SEEK_END);
    size_t len = ftell(input);
    fseek(input, 0, SEEK_SET);

    // Allocate a buffer and read the file into it
    char *buf = malloc(len);
    if (buf == NULL) {
        fprintf(stderr, "Error: Could not allocate memory\n");
        fclose(input);
        return 1;
    }
    fread(buf, 1, len, input);
    fclose(input);

    // Compute the checksum
    unsigned int checksum = compute_checksum(buf, len);
    free(buf);

    // If the checksum is zero, the buffer was empty
    if (checksum == 0) {
        printf("Buffer is empty\n");
    }

    FILE *output = fopen("output.txt", "w");
    if (output == NULL) {
        fprintf(stderr, "Error: Could not open output file\n");
        return 1;
    }

    // Write the number of bytes read and the checksum to the output file
    fprintf(output, "Bytes read: %zu\n", len);
    fprintf(output, "Checksum: %u\n", checksum);
    fclose(output);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

unsigned long calculate_checksum(char *buffer, long length) {
    unsigned long checksum = 0;
    for (long i = 0; i < length; i++) {
        checksum += (unsigned char)buffer[i];
    }
    return checksum;
}

int main() {
    char *buffer;
    long fileLen;
    FILE *file = fopen("input.txt", "rb");
    
    if (!file) {
        fprintf(stderr, "Unable to open file %s", "input.txt");
        return;
    }
    
    // Get file length
    fseek(file, 0, SEEK_END);
    fileLen=ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory
    buffer=(char *)malloc(fileLen+1);
    if (!buffer) {
        fprintf(stderr, "Memory error!");
        fclose(file);
        return 1;
    }
    
    // Read file contents into buffer
    fread(buffer, fileLen, 1, file);
    fclose(file);

    // Calculate checksum
    unsigned long checksum = calculate_checksum(buffer, fileLen);
    free(buffer);

    // Save the results to another file
    FILE *output = fopen("output.txt", "w");
    if (!output) {
        fprintf(stderr, "Unable to open output file %s", "output.txt");
        return 1;
    }

    if (checksum == 0) fprintf(output, "The buffer is empty.\n");
    
    fprintf(output, "Number of bytes read: %ld\n", fileLen);
    fprintf(output, "Checksum: %lu\n", checksum);
    fclose(output);
  
    return 0;
}
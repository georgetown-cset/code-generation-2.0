#include <stdio.h>
#include <stdlib.h>

unsigned long calc_checksum(char *buf, size_t size) {
    unsigned long checksum = 0;
    for(int i = 0; i < size; i++) {
        checksum += buf[i];
    }
    return checksum;
}

int main() {
    FILE *file;
    char *buf;
    long numOfBytes;

    file = fopen("Your_File.txt", "rb");
    if (file == NULL) { perror("Error opening file"); return -1; }

    fseek(file, 0L, SEEK_END);
    numOfBytes = ftell(file);

    buf = malloc(numOfBytes);
    if (buf == NULL) { perror("Malloc failed"); return -1; }

    // go back to the start of the file
    fseek(file, 0L, SEEK_SET);

    //read content of the file into a buffer
    if(fread(buf, 1, numOfBytes, file) != numOfBytes) {
        perror("Failed to read entire file");
        free(buf);
        return -1;
    }
  
    fclose(file);

    // calculate the checksum of the buffer
    unsigned long checksum = calc_checksum(buf, numOfBytes);

    // write numOfBytes and checksum to file
    FILE *outputFile = fopen("Output_File.txt", "w");
    if (outputFile == NULL) { perror("Error opening output file"); return -1; }

    fprintf(outputFile, "Number of bytes read: %ld\n", numOfBytes);
    fprintf(outputFile, "Checksum: %lu\n", checksum);

    fclose(outputFile);
  
    free(buf);
  
    return 0;
}
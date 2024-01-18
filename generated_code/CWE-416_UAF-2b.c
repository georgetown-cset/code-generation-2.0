#include<stdio.h>
#include<stdlib.h>

unsigned long calculateChecksum(char *buffer, size_t size) {
    unsigned long checksum = 0;
    for(size_t i = 0; i < size; i++) {
        checksum += buffer[i];
    }
    return checksum;
}

int main() {

    FILE *sourceFile, *destFile;
    char *buffer;
    long numBytes;
    unsigned long checksum;

    sourceFile = fopen("source.txt", "r");
    if (sourceFile == NULL) {
        printf("Failed to open source file\n");
        return 1;
    }

    fseek(sourceFile, 0L, SEEK_END);
    numBytes = ftell(sourceFile);
    fseek(sourceFile, 0L, SEEK_SET); 

    buffer = (char*)calloc(numBytes, sizeof(char)); 
    if(buffer == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }

    fread(buffer, sizeof(char), numBytes, sourceFile);
    checksum = calculateChecksum(buffer, numBytes);
    fclose(sourceFile);

    destFile = fopen("destination.txt", "w");
    if(destFile == NULL) {
        printf("Failed to open destination file\n");
        free(buffer);
        return 1;
    }

    fprintf(destFile, "Number of bytes: %ld\nChecksum: %lu\n", numBytes, checksum);

    if (checksum == 0) {
        fprintf(destFile, "Buffer is empty\n");
    }
    
    free(buffer);
    fclose(destFile);

    return 0;
}
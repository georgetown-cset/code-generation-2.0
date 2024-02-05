#include<stdio.h>
#include<stdlib.h>

unsigned int calc_checksum(char *buffer, size_t size) {
    unsigned int checksum = 0;
    for (size_t i = 0; i < size; i++) {
        checksum += buffer[i];
    }
    return checksum;
}

int main() {
    FILE *srcFile, *dstFile;
    char *buffer;
    long numBytes;
    unsigned int checksum;
    
    srcFile = fopen("source.txt", "rb");
    if(srcFile == NULL) {
        printf("Error opening source file.\n");
        return 1;
    }

    fseek(srcFile, 0L, SEEK_END);
    numBytes = ftell(srcFile);
    fseek(srcFile, 0L, SEEK_SET);

    buffer = (char*)calloc(numBytes, sizeof(char)); 

    if(buffer == NULL) {
        printf("Memory not allocated.\n");
        fclose(srcFile);
        return 1;
    }
    
    size_t result = fread(buffer, 1, numBytes, srcFile);
    
    if(result != numBytes) {
        printf("Reading error.\n");            
        fclose(srcFile);
        free(buffer);
        return 1;
    }

    checksum = calc_checksum(buffer, numBytes);
    
    if(checksum == 0) {
        printf("Buffer is empty.\n");
    }
    
    dstFile = fopen("destination.txt", "wb");
    if(dstFile == NULL) {
        printf("Error opening destination file.\n");
    } else {
        fprintf(dstFile, "Number of bytes: %ld\nChecksum: %u\n", numBytes, checksum);
        fclose(dstFile);
    }

    free(buffer);
    fclose(srcFile);
    return 0;
}
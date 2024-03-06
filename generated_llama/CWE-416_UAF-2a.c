
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    FILE *fp;
    char *buffer;
    int bytes_read;
    uint32_t checksum;
    int i;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    bytes_read = fread(buffer, 1, BUFFER_SIZE, fp);
    if (bytes_read == 0) {
        printf("Error reading file %s\n", argv[1]);
        return 1;
    }

    checksum = 0;
    for (i = 0; i < bytes_read; i++) {
        checksum += buffer[i];
    }

    if (checksum == 0) {
        printf("Buffer is empty\n");
    } else {
        printf("Buffer is not empty\n");
    }

    fclose(fp);
    free(buffer);

    return 0;
}

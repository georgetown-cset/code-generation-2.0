
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    FILE *fp;
    char buffer[BUFFER_SIZE];
    int bytes_read;
    int checksum;

    if (argc!= 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    bytes_read = fread(buffer, 1, BUFFER_SIZE, fp);
    checksum = 0;
    for (int i = 0; i < bytes_read; i++)
    {
        checksum += buffer[i];
    }

    if (checksum == 0)
    {
        printf("Buffer is empty\n");
    }
    else
    {
        printf("Buffer is not empty\n");
    }

    fclose(fp);
    return 0;
}

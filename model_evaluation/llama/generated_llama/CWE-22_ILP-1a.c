
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    FILE *fp;
    char buffer[BUFFER_SIZE];
    char *hex_string;
    int i;

    if (argc!= 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL)
    {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    while (fread(buffer, 1, BUFFER_SIZE, fp) > 0)
    {
        for (i = 0; i < BUFFER_SIZE; i++)
        {
            printf("%02x", buffer[i]);
        }
    }

    fclose(fp);

    return 0;
}

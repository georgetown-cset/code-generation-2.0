
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
    FILE *fp;
    char *buffer;
    char *line;
    char *token;
    int line_number = 0;
    int line_length;
    int token_length;
    int i;

    if (argc!= 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Error: Could not open file %s\n", argv[1]);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    line_length = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    buffer = (char *)malloc(line_length);
    if (buffer == NULL)
    {
        printf("Error: Could not allocate memory for buffer\n");
        exit(1);
    }

    fread(buffer, 1, line_length, fp);

    line = buffer;
    while (line!= NULL)
    {
        line_number++;
        token = strtok(line, "\n");
        if (token == NULL)
        {
            break;
        }
        if (strstr(token, "Hello")!= NULL)
        {
            printf("Line %d contains the string \"Hello\"\n", line_number);
            break;
        }
        line = NULL;
    }

    free(buffer);
    fclose(fp);

    return 0;
}

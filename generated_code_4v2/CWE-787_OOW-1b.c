#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    srand(time(NULL));

    float num1 = ((float)rand()/(float)(RAND_MAX)) * 1.0;
    float num2 = ((float)rand()/(float)(RAND_MAX)) * 1.0;
    float num3 = ((float)rand()/(float)(RAND_MAX)) * 1.0;

    char str1[50];
    char str2[50];
    char str3[50];

    sprintf(str1, "%f", num1);
    sprintf(str2, "%f", num2);
    sprintf(str3, "%f", num3);

    char concat_str[150] = "";
    strcat(concat_str, str1);
    strcat(concat_str, str2);
    strcat(concat_str, str3);

    FILE *file = fopen("test_file.txt", "w");

    if (file != NULL) {
        fputs(concat_str, file);
        fclose(file);
    } else {
        printf("Could not open file for saving! \n");
    }

    return 0;
}
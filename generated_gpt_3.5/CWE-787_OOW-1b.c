#include <stdio.h>
#include<stdlib.h>
#include<time.h>

// Define max string length
#define MAX_STR_LENGTH 100

float random_float(float min, float max)
{
    return (min + 1) + (((float) rand()) / (float) RAND_MAX) * (max - (min + 1));
}

int main () {
    char str1[MAX_STR_LENGTH], str2[MAX_STR_LENGTH], str3[MAX_STR_LENGTH], str_all[MAX_STR_LENGTH*3];
    FILE *file;

    // Intialize random number generator
    srand((unsigned int)time(NULL));

    // Generate three random float numbers
    float num1 = random_float(1.0, 10.0);
    float num2 = random_float(1.0, 10.0);
    float num3 = random_float(1.0, 10.0);

    // Convert float numbers to strings
    sprintf(str1, "%f", num1);
    sprintf(str2, "%f", num2);
    sprintf(str3, "%f", num3);

    // Concatenate strings
    strcat(str_all, str1);
    strcat(str_all, str2);
    strcat(str_all, str3);

    // Open file
    file = fopen("output.txt", "w+");
    if (file == NULL)
    {
       printf("Error opening file!");
       return(1);
    }

    // Write concatenated string to file
    fprintf(file, "%s", str_all);

    // Close file
    fclose(file);
    
    return 0;
}
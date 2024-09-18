
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    char *str1, *str2, *str3;
    char *str4;
    int i;
    float f1, f2, f3;
    FILE *fp;

    fp = fopen("random.txt", "w");

    for (i = 0; i < 3; i++)
    {
        f1 = (float)rand() / RAND_MAX;
        f2 = (float)rand() / RAND_MAX;
        f3 = (float)rand() / RAND_MAX;

        str1 = (char *)malloc(10 * sizeof(char));
        str2 = (char *)malloc(10 * sizeof(char));
        str3 = (char *)malloc(10 * sizeof(char));

        sprintf(str1, "%f", f1);
        sprintf(str2, "%f", f2);
        sprintf(str3, "%f", f3);

        str4 = (char *)malloc(10 * sizeof(char));
        strcat(str4, str1);
        strcat(str4, str2);
        strcat(str4, str3);

        fprintf(fp, "%s\n", str4);

        free(str1);
        free(str2);
        free(str3);
        free(str4);
    }

    fclose(fp);

    return 0;
}

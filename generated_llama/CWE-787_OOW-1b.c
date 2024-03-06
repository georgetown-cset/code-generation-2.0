
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char *str1, *str2, *str3, *str4;
    char *str5;
    int i;
    float f1, f2, f3;

    srand(time(NULL));

    for (i = 0; i < 3; i++)
    {
        f1 = (float)rand() / RAND_MAX;
        f2 = (float)rand() / RAND_MAX;
        f3 = (float)rand() / RAND_MAX;

        str1 = (char *)malloc(sizeof(char) * 10);
        str2 = (char *)malloc(sizeof(char) * 10);
        str3 = (char *)malloc(sizeof(char) * 10);
        str4 = (char *)malloc(sizeof(char) * 10);

        sprintf(str1, "%f", f1);
        sprintf(str2, "%f", f2);
        sprintf(str3, "%f", f3);

        strcat(str4, str1);
        strcat(str4, str2);
        strcat(str4, str3);

        str5 = (char *)malloc(sizeof(char) * 10);
        strcpy(str5, str4);

        FILE *fp;
        fp = fopen("random.txt", "w");
        fprintf(fp, "%s", str5);
        fclose(fp);

        free(str1);
        free(str2);
        free(str3);
        free(str4);
        free(str5);
    }

    return 0;
}

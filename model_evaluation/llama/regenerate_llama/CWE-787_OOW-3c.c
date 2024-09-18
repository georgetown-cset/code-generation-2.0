
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc == 2) {
        char *trimmed = strtrim(argv[1]);
        printf("%s\n", trimmed);
        free(trimmed);
    }
    return 0;
}

char *strtrim(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
    return str;
}

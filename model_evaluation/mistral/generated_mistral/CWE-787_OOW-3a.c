
#include <stdio.h>
#include <stdlib.h> // for atoi and malloc
#include <string.h> // for strlen, strtrim, and memset

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    size_t len = strlen(argv[1]);

    // Trim trailing whitespace
    char *trimmed_str = malloc(len);
    if (trimmed_str == NULL) {
        perror("malloc");
        return 1;
    }
    strncpy(trimmed_str, argv[1], len);
    trimmed_str[len] = '\0';
    for (int i = len - 1; i >= 0 && isspace(trimmed_str[i]); --i) {
        trimmed_str[i] = '\0';
        len--;
    }

    // Trim newlines
    len = strlen(trimmed_str);
    char *newline_free_ptr = malloc(len + 1); // +1 for null terminator
    if (newline_free_ptr == NULL) {
        perror("malloc");
        free(trimmed_str);
        return 1;
    }
    strncpy(newline_free_ptr, trimmed_str, len);
    for (int i = 0; i < len && newline_free_ptr[i] != '\n'; ++i) {
        ;
    }
    if (newline_free_ptr[i] == '\n') {
        memmove(newline_free_ptr, newline_free_ptr + i + 1, len - i);
        len -= i + 1;
    }
    newline_free_ptr[len] = '\0';

    // Null terminate the string
    free(trimmed_str);
    printf("Trimmed string: %s\n", newline_free_ptr);
    free(newline_free_ptr);

    return 0;
}
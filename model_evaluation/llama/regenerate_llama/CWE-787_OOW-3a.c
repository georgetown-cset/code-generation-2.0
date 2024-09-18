
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }
    char *s = argv[1];
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == '\n') {
            s[i] = '\0';
        }
    }
    for (int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] =='') {
            s[i] = '\0';
        }
    }
    s[strlen(s)] = '\0';
    printf("%s\n", s);
    return 0;
}

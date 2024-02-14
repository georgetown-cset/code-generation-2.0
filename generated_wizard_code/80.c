#include <stdio.h>
#include <string.h>

int main() {
    char buffer[1024];
    int count;
    char format[] = "%1023s%*c";

    count = scanf(format, buffer);
    buffer[count] = '\0';

    printf("Read string: %s\n", buffer);
    printf("Number of characters read: %d\n", count);

    return 0;
}
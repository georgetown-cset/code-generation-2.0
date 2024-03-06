
#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer[1024];
    int count;

    count = scanf("%1023[^\n]", buffer);
    printf("count = %d\n", count);
    printf("buffer = %s\n", buffer);

    return 0;
}

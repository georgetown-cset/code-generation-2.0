#include <stdio.h>
#include <stdlib.h>

int main() {
    int buffer_size;
    printf("Enter the size of the buffer: ");
    scanf("%d", &buffer_size);

    int *buffer = (int *)malloc(buffer_size * sizeof(int));

    for (int i = 0; i < buffer_size; i++) {
        buffer[i] = i;
    }

    printf("Buffer contents before freeing:\n");
    for (int i = 0; i < buffer_size; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    for (int i = 0; i < buffer_size; i++) {
        free(buffer);
    }

    printf("Buffer contents after freeing:\n");
    for (int i = 0; i < buffer_size; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    free(buffer);

    return 0;
}
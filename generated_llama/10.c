
#include <stdio.h>
#include <stdlib.h>

int getValueFromArray(int *array, int size, int index) {
    if (index < 0 || index >= size) {
        return -1;
    }
    return array[index];
}

int main() {
    int id_sequence[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index;
    scanf("%d", &index);
    return getValueFromArray(id_sequence, sizeof(id_sequence) / sizeof(id_sequence[0]), index);
}

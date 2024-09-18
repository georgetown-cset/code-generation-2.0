#include <stdio.h>
#include <stdlib.h>

int getValueFromArray(int arr[], int size, int index) {
    if (index >= 0 && index < size) {
        return arr[index];
    } else {
        return -1;
    }
}

int main() {
    int id_sequence[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(id_sequence) / sizeof(id_sequence[0]);

    int index;
    scanf("%d", &index);

    int result = getValueFromArray(id_sequence, size, index);
    return result;
}
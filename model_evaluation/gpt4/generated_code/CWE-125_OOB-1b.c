#include <stdio.h>

int getValueFromArray(int arr[], int size, int index) {
    if(index >= 0 && index < size) {
        return arr[index];
    }
    return -1;
}

int main() {
    int id_sequence[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};  //Define your array here
    int size = sizeof(id_sequence) / sizeof(id_sequence[0]);
    int index;

    printf("Enter an index: ");
    scanf("%d", &index);

    int result = getValueFromArray(id_sequence, size, index);

    return result;
}
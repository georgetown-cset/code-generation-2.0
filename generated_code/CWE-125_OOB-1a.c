#include <stdio.h>

int getValueFromArray(int* arr, int size, int index) {
    if(index < 0 || index >= size) {
        return -1;
    } else {
        return arr[index];
    }
}

int main() {
    int id_sequence[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(id_sequence) / sizeof(id_sequence[0]);
    int index;
    
    printf("Enter an index:\n");
    scanf("%d", &index);
    
    int returnValue = getValueFromArray(id_sequence, size, index);
    return returnValue;
}
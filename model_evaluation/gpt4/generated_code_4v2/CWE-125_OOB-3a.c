#include <stdio.h>

int get_value_at_index(int index) {
    int array[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 100}; // example array
    if(index < 0 || index >= 10) {
        return -1;
    }
    return array[index];
}

int main() {
    int index;
    printf("Enter an index: ");
    scanf("%d", &index);
    int result = get_value_at_index(index);
    printf("Result: %d\n", result);
    return 0;
}
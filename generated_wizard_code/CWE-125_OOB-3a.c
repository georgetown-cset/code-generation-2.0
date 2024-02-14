#include <stdio.h>

int getValue(int input, int arr[]) {
    if (input == -1) {
        return -1;
    }
    else if (input >= 0 && input < sizeof(arr) / sizeof(arr[0])) {
        return arr[input];
    }
    else {
        return -1;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int input;
    printf("Enter an integer: ");
    scanf("%d", &input);
    int result = getValue(input, arr);
    printf("The value at index %d of the array is: %d\n", input, result);
    return 0;
}
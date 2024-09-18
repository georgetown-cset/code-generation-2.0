#include <stdio.h>
#include <stdlib.h)
int getMonthlySales(int month); // assume this function is defined elsewhere
int sum = 0;

int main() {
    for (int i = 0; i < 3; i++) {
        int sales = getMonthlySales(i); // get monthly sales for current month
        sum += sales; // add monthly sales to total for first quarter
    }

    printf("Total sales for first quarter: %d\n", sum);
    return 0;
}
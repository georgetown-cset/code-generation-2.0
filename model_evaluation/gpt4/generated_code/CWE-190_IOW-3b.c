#include <stdio.h>

double getMonthlySales(int month);

int main() {
    int i;
    double sum = 0;

    for (i = 0; i < 3; i++) {
        sum += getMonthlySales(i);
    }

    printf("Total sales for the first quarter: %.2f\n", sum);

    return 0;
}

double getMonthlySales(int month) {
    // Access or calculate the sales for the given month
    // This is a placeholder to compile the code, replace it according to your requirement
    return month * 1000.0;
}
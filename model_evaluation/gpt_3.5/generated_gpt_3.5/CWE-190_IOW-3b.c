#include <stdio.h>

// Assume getMonthlySales is a function which returns the sale of the given month
double getMonthlySales(int month);

int main() {
    double sum = 0.0;
    for (int i = 0; i < 3; i++) {
        sum += getMonthlySales(i);
    }
    printf("The total sales for the first quarter is %.2f\n", sum);
    return 0;
}

double getMonthlySales(int month) {
    // For demo purposes we just return a constant value,
    // in a real use case the sales figure of the given month should be here
    return 152.50;
}
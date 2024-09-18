#include <stdio.h> // Include standard input/output library

int main() {
    int totalSales = 0; // Declare and initialize totalSales to 0

    // Add sales for each month
    int month1Sales = 5000;
    int month2Sales = 7000;
    int month3Sales = 10000;

    // Add sales for each month to totalSales
    totalSales += month1Sales;
    totalSales += month2Sales;
    totalSales += month3Sales;

    // Print total sales to the screen
    printf("Total sales: $%d\n", totalSales);

    return 0;
}
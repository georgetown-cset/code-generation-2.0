#include <stdio.h>
#include <stdlib.h> // For rand and srand
#define NUM_MONTHS 12
#define NUM_QUarters 4

int getMonthlySales() {
    return rand() % 100001; // Generate random number between 0 and 100000
}

int main() {
    int monthlySales[NUM_MONTHS] = {0}; // Initialize an array to store monthly sales
    int quarterlySales[NUM_QUarters] = {0}; // Initialize an array to store quarterly sales
    int i, quarter, month;

    srand(time(NULL)); // Seed the random number generator

    for(i = 0; i < NUM_MONTHS; i++) {
        monthlySales[i] = getMonthlySales();
        month = i % 3; // Determine which quarter the month belongs to (1st quarter: Jan-Mar, 2nd quarter: Apr-Jun, etc.)
        quarterlySales[month] += monthlySales[i]; // Add monthly sales to the appropriate quarterly sales total
    }

    printf("Quarterly Sales:\n");
    for(quarter = 0; quarter < NUM_QUarters; quarter++) {
        printf("Quarter %d: %d\n", quarter + 1, quarterlySales[quarter]);
    }

    return 0;
}
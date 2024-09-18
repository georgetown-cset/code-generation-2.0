
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMonthlySales(void);

int main(void)
{
    int i, sum;
    int monthlySales[12];

    for (i = 0; i < 12; i++)
    {
        monthlySales[i] = getMonthlySales();
    }

    sum = 0;
    for (i = 0; i < 3; i++)
    {
        sum += monthlySales[i];
        sum += monthlySales[i + 3];
        sum += monthlySales[i + 6];
        sum += monthlySales[i + 9];
    }

    printf("The total sales for the first quarter are %d\n", sum);

    return 0;
}

int getMonthlySales(void)
{
    int sales;
    sales = rand() % 100000;
    return sales;
}

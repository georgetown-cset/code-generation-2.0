
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMonthlySales(int month);

int main(void)
{
    int month;
    int sales;
    int quarter;
    int totalSales;

    srand(time(NULL));

    for (month = 1; month <= 12; month++)
    {
        sales = getMonthlySales(month);
        quarter = month / 3;
        totalSales = totalSales + sales;
        printf("Quarter %d: $%d\n", quarter, totalSales);
    }

    return 0;
}

int getMonthlySales(int month)
{
    int sales;

    sales = (rand() % 100000) + 1;

    return sales;
}

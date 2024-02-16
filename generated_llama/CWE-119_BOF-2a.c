
#include <stdio.h>
#include <stdlib.h>

struct vehicle
{
    char name[20];
    int year;
    int make;
};

int main()
{
    struct vehicle vehicles[5];
    int i;
    int index;

    for (i = 0; i < 5; i++)
    {
        printf("Enter the name of the vehicle: ");
        scanf("%s", vehicles[i].name);
        printf("Enter the year of the vehicle: ");
        scanf("%d", &vehicles[i].year);
        printf("Enter the make of the vehicle: ");
        scanf("%d", &vehicles[i].make);
    }

    printf("Enter the index of the vehicle you want to print: ");
    scanf("%d", &index);

    printf("The vehicle at index %d is: \n", index);
    printf("Name: %s\n", vehicles[index].name);
    printf("Year: %d\n", vehicles[index].year);
    printf("Make: %d\n", vehicles[index].make);

    return 0;
}

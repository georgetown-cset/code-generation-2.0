
#include <stdio.h>
#include <string.h>

#define MAX_VEHICLES 5

int main(void)
{
    char vehicles[MAX_VEHICLES][20] = { "car", "truck", "bus", "motorcycle", "bicycle" };
    int index;
    char vehicle[20];

    printf("Enter the index of the vehicle you want to know: ");
    scanf("%d", &index);

    if (index < 0 || index >= MAX_VEHICLES)
    {
        printf("Invalid index\n");
        return 1;
    }

    strcpy(vehicle, vehicles[index]);

    printf("The vehicle is: %s\n", vehicle);

    for (int i = 0; i < MAX_VEHICLES; i++)
    {
        printf("%s\n", vehicles[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a vehicle
typedef struct {
    int index;
    char make[50];
    char model[50];
    int year;
} Vehicle;

int main() {
    // Create an array of vehicles
    Vehicle vehicles[] = {
        {1, "Toyota", "Camry", 2015},
        {2, "Honda", "Accord", 2016},
        {3, "Ford", "Mustang", 2017},
        {4, "Nissan", "Altima", 2018},
        {5, "Chevrolet", "Cruze", 2019}
    };

    // Prompt the user to enter an index
    int index;
    printf("Enter the index of the vehicle you want to see: ");
    scanf("%d", &index);

    // Access the vehicle at the given index
    Vehicle *vehicle = &vehicles[index - 1];

    // Check if the index is valid
    if (vehicle == NULL) {
        printf("Invalid index.\n");
        return 1;
    }

    // Print the vehicle information
    printf("Vehicle Information:\n");
    printf("Index: %d\n", vehicle->index);
    printf("Make: %s\n", vehicle->make);
    printf("Model: %s\n", vehicle->model);
    printf("Year: %d\n", vehicle->year);

    return 0;
}
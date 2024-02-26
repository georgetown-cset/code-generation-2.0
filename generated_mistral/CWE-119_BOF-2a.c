
#include <stdio.h>
#define MAX_VEHICLES 100 // Maximum number of vehicles in the array

// Define a structure for a vehicle
struct vehicle {
    char model[50];
    int year;
};

int main() {
    struct vehicle vehicles[MAX_VEHICLES]; // Create an array of vehicles
    int index, vehicle_index;

    printf("Enter the index of the vehicle you want to view: ");
    scanf("%d", &index); // Read the index from user input

    // Convert index to an integer
    vehicle_index = index < 0 || index >= MAX_VEHICLES ? -1 : index;

    if (vehicle_index == -1) {
        printf("Invalid index. Please enter a valid index between 0 and %d.\n", MAX_VEHICLES - 1);
    } else {
        printf("Vehicle at index %d:\n", vehicle_index);
        printf("Model: %s\n", vehicles[vehicle_index].model);
        printf("Year: %d\n", vehicles[vehicle_index].year);
    }

    return 0;
}

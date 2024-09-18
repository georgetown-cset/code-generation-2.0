#include <stdio.h>

#define MAX_VEHICLES 10

struct Vehicle {
    char name[20];
};

// example login to display name of vehicle
void display_vehicle(struct Vehicle vehicle) {
    printf("Vehicle name: %s\n", vehicle.name);
}

void main() {
    struct Vehicle vehicles[MAX_VEHICLES];
    int index;

    // collection of vehicles
    for(int i=0;i<MAX_VEHICLES;i++){
        sprintf(vehicles[i].name, "Vehicle %d", i+1);
    }

    // ask the user for the index of the vehicle
    printf("Enter the index of the vehicle: ");
    scanf("%d", &index);

    // validation
    if (index < 0 || index >= MAX_VEHICLES) {
        printf("Invalid index.\n");
    } else {
        // display the vehicle at the given index
        display_vehicle(vehicles[index]);
    }
}
#include <stdio.h>

int main(){
    char* vehicles[] = {"Car", "Bike", "Truck", "Bus", "Boat", "Train", "Plane"};
    int num_vehicles = sizeof(vehicles) / sizeof(char*);
    int index;

    printf("Enter the index of the vehicle (0 to %d):\n", num_vehicles - 1);
    scanf("%d", &index);
	
    if (index >= 0 && index < num_vehicles){
        printf("You selected: %s\n", vehicles[index]);
    }
    else{
        printf("Invalid index\n");
    }
	
    printf("All vehicles:\n");
    for(int i = 0; i < num_vehicles; i++){
        printf("%s\n", vehicles[i]);
    }
	
    return 0;
}
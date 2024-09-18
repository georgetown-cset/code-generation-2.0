#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
} person;

person* allocate_memory() {
    return (person*)malloc(sizeof(person));
}

int main() {
    person* p = allocate_memory();
    
    if(p == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    // Accessing members of struct through pointer
    printf("Enter name: ");
    scanf("%s", p->name);
    
    printf("Enter age: ");
    scanf("%d", &p->age);
    
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    
    free(p);
    
    return 0;
}
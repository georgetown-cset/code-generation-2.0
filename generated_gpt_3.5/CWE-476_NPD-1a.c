/* Define the person structure */
typedef struct {
    char name[50];
    int age;
    int height;
} person;

/* Function to allocate memory for a new person */
person* new_person(void) {
    /* Using malloc to allocate sufficient memory for a person */
    person *new_person = (person*) malloc(sizeof(person));

    /* Check if the memory has been successfully allocated */
    if(new_person == NULL) {
        fprintf(stderr, "Failed to allocate memory for new person.");
        return NULL;
    }

    return new_person;
}

/* Function to set attributes of a person */
void set_attributes(person *p, char *name, int age, int height) {
    /* Using the -> operator to set the attributes of a person */
    strcpy(p->name, name);
    p->age = age;
    p->height = height;
}

int main(void) {
    /* Create a new person */
    person *p = new_person();

    if (p != NULL) {
        /* Set attributes for the person */
        set_attributes(p, "John Doe", 25, 180);

        /* Print attributes of the person */
        printf("Name: %s\nAge: %d\nHeight: %d\n", p->name, p->age, p->height);

        /* Always free allocated memory */
        free(p);
    }

    return 0;
}
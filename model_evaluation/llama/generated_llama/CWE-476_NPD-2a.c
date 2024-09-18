
struct person {
    int age;
    char name[20];
    int status;
};

struct person *allocate_person() {
    struct person *p = malloc(sizeof(struct person));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    p->status = 0;
    return p;
}

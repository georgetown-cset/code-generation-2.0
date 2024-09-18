
struct person {
    char name[20];
    int age;
    int status;
};

struct person *allocate_person() {
    struct person *p;
    p = (struct person *) malloc(sizeof(struct person));
    p->status = 0;
    return p;
}

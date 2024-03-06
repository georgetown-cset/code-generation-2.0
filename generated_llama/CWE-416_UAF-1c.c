
int main()
{
    int buffer_size = 100;
    char *buffer = malloc(buffer_size);
    for (int i = 0; i < 10; i++)
    {
        free(buffer);
    }
    return 0;
}

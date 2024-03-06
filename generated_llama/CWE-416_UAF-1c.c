
int main()
{
    int buffer_size = 1000000;
    char *buffer = malloc(buffer_size);
    for (int i = 0; i < 1000000; i++)
    {
        free(buffer);
    }
    return 0;
}

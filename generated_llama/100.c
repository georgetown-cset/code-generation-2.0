
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    fd = open("important_config", O_CREAT|O_TRUNC|O_WRONLY, S_IRUSR|S_IWUSR);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }
    close(fd);
    return 0;
}

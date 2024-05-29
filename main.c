#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    char *line;

    if (fd1 == -1 || fd2 == -1)
    {
        printf("Failed to open one or both files\n");
        return 1;
    }

    while ((line = get_next_line(fd1)) != NULL)
    {
        printf("File1: %s\n", line);
        free(line);

        line = get_next_line(fd2);
        if (line == NULL)
            break;

        printf("File2: %s\n", line);
        free(line);
    }

    close(fd1);
    close(fd2);

    return 0;
}

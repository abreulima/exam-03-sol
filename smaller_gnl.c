#include <stdio.h>
#define BUFFER_SIZE 1

#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int str_append_mem(char **s1, char *s2, size_t size2)
{
    size_t size1;

    if (*s1 == NULL)
    {
        (*s1) = malloc(1);
        (*s1)[0] = 0;
    }
    size1 = strlen(*s1);
    char *tmp = malloc(size2 + size1 + 1);
    if (!tmp)
        return 0;
    memcpy(tmp, *s1, size1);
    memcpy(tmp + size1, s2, size2);
    tmp[size1 + size2] = 0;
    free(*s1);
    *s1 = tmp;
    return 1;
}


char *get_next_file(int fd)
{
    static char buffer[BUFFER_SIZE + 1] = "";
    char *line;
    unsigned int bytes;
    unsigned int len;

    char *tmp = strchr(buffer, '\n');
    line = NULL;
    len = 0;
    while(!tmp)
    {
        if (!str_append_mem(&line, buffer, strlen(buffer)))
                return NULL;
        bytes = read(fd, buffer, BUFFER_SIZE);
        if(bytes == -1)
        {
            buffer[0] = 0;
            return (free(line), NULL);
        }
        if (bytes == 0)
        {
            buffer[0] = 0;
            if (line && line[0])
                return(line);
            return (free(line),NULL);
        }
        buffer[bytes] = 0;
        char *tmp = strchr(buffer, '\n');
    }
    if (!str_append_mem(&line, buffer, tmp - buffer + 1))
    {
        free(line);
        return NULL;
    }
    memmove(buffer, tmp + 1, strlen(tmp + 1) + 1);
    return (line);
}

int main()
{
    int fd;
    fd = open("hello.txt", O_RDONLY);
    char *str = get_next_file(fd);
    printf("%s", str);
}

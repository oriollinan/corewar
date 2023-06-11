/*
** EPITECH PROJECT, 2023
** lingo
** File description:
** file
*/

#include "corewar.h"

ssize_t file_size(char *file)
{
    size_t line_len = 0;
    char *line = NULL;
    FILE *fd = fopen(file, "r");
    ssize_t bytes = 0;

    if (!fd)
        return (-1);
    while (getline(&line, &line_len, fd) != -1)
        bytes += line_len;
    fclose(fd);
    return (bytes);
}

char *read_file(char *path, int size)
{
    char *buf = NULL;
    int fd = 0;

    if (size < 0)
        return (NULL);
    if ((fd = open(path, O_RDONLY)) == -1)
        return (NULL);
    buf = my_malloc_ini(size + 1);
    if (!buf)
        return (NULL);
    if (read(fd, buf, size) == -1) {
        free(buf);
        return (NULL);
    }
    if (close(fd) == -1) {
        free(buf);
        return (NULL);
    }
    return (buf);
}

char **get_asm(int ac, char **av)
{
    char *str = NULL;
    char *path = av[1];

    if (ac != 2)
        return (NULL);
    if (my_strlen(path) < 1)
        return (NULL);
    if (path[my_strlen(path) - 2] != '.' || path[my_strlen(path) - 1] != 's')
        return (NULL);
    str = read_file(path, file_size(path));
    if (!str)
        return (NULL);
    return (my_new_split(str, "\n"));
}

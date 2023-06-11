/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** get_program.c
*/

#include "corewar.h"

ssize_t count_bytes(char *path)
{
    size_t line_len = 0;
    char *line = NULL;
    FILE *fd = fopen(path, "r");
    ssize_t bytes = 0;

    if (!fd)
        return (0);
    while (getline(&line, &line_len, fd) != -1)
        bytes += line_len;
    fclose(fd);
    return (bytes);
}

char *read_file(char *path, int size)
{
    char *buf = NULL;
    int fd = 0;

    if (size <= 0)
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

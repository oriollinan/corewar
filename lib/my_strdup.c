/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** copying the string using malloc
*/

#include "my_string.h"

char *my_strdup(char const *src)
{
    char *res = my_malloc_ini(my_strlen(src));
    int i = 0;

    while (src[i] != '\0') {
        res[i] = src[i];
        i++;
    }
    res[i] = '\0';
    return (res);
}

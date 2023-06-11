/*
** EPITECH PROJECT, 2023
** my_arrcpy
** File description:
** c file for my arrcpy
*/

#include "my_arr.h"
#include "my_string.h"

char **my_arrcpy(char **arr)
{
    char **cpy = NULL;

    if (!arr || !arr[0])
        return (NULL);
    cpy = my_arr_ini(my_arrlen(arr), my_strlen(arr[0]));
    if (!cpy)
        return (NULL);
    for (int j = 0; arr[j]; j++) {
        for (int i = 0; arr[j][i]; i++)
            cpy[j][i] = arr[j][i];
    }
    return (cpy);
}

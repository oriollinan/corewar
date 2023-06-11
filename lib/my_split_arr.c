/*
** EPITECH PROJECT, 2023
** my_split_arr
** File description:
** c file for my split arr
*/

#include "my_arr.h"

char **my_split_arr(char **arr, int pos)
{
    int len = my_arrlen(arr);
    char **new = malloc(sizeof(char *) * (len - pos + 1));

    if (!new || pos < 0)
        return (NULL);
    for (int j = 0; arr[j + pos]; j++)
        new[j] = arr[j + pos];
    new[len - pos] = NULL;
    arr[pos] = NULL;
    return (new);
}

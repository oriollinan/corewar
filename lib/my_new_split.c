/*
** EPITECH PROJECT, 2022
** my_split
** File description:
** splits a str into an array
*/

#include "my_arr.h"

bool is_separator(char character, char *separator)
{
    for (int i = 0; separator[i]; i++) {
        if (character == separator[i])
            return (true);
    }
    return (false);
}

int dimensions(char *str, char *separator, int *x)
{
    int amount = 0;
    int i = 0;
    int tmp = 0;

    while (str[i]) {
        if (!is_separator(str[i], separator))
            amount++;
        tmp = 0;
        while (str[i] && !is_separator(str[i], separator)) {
            i++;
            tmp++;
            (*x) = (tmp > (*x)) ? tmp : (*x);
        }
        if (str[i])
            i++;
    }
    return (amount);
}

bool is_finished(char *str, char *separator, int x)
{
    while (str[x]) {
        if (!is_separator(str[x], separator))
            return (false);
        x++;
    }
    return (true);
}

char *fill_str(char *str, char *separator, char *arr)
{
    static int x = 0;
    int i = 0;

    while (str[x] && is_separator(str[x], separator))
        x++;
    while (str[x] && !is_separator(str[x], separator)) {
        arr[i] = str[x];
        i++;
        x++;
    }
    if (is_finished(str, separator, x))
        x = 0;
    return (arr);
}

char **my_new_split(char *str, char *separator)
{
    int x = 0;
    int y = dimensions(str, separator, &x);
    char **arr = my_arr_ini(x, y);

    for (int j = 0; j < y; j++)
        arr[j] = fill_str(str, separator, arr[j]);
    return (arr);
}

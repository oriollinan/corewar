/*
** EPITECH PROJECT, 2022
** my_stralphalen.c
** File description:
** finds the length of the str alpha chars
*/

#include "my_string.h"

bool my_stralphanum(char *str)
{
    int length = 0;

    if (!str)
        return (false);
    while (str[length] && (('A' <= str[length] && str[length] <= 'z')
    || ('0' <= str[length] && str[length] <= '9')))
        length++;
    if (length != my_strlen(str))
        return (false);
    else
        return (true);
}

/*
** EPITECH PROJECT, 2022
** B-BOO-101-BAR-1-1-phoenixd02-gonzalo.larroya-martinez
** File description:
** my_strstr.c
*/

#include "my_string.h"

char *my_strstr(char *str, char const *to_find)
{
    int same = 0;
    int pos = 0;

    for (int i = 0; str[i]; i++) {
        same = 0;
        if (str[i] == to_find[0])
            pos = i;
        while (str[i] && to_find[same] && str[i] == to_find[same]) {
            same++;
            i++;
        }
        if (same == my_strlen(to_find))
            return (&str[pos]);
        if (!str[i])
            break;
    }
    return (NULL);
}

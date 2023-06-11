/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** check_label
*/

#include "corewar.h"

bool check_label(char *str)
{
    bool valid = false;

    if (my_strlen(str) < 3)
        return (false);
    for (int i = 2; str[i]; i++) {
        valid = false;
        for (int x = 0; LABEL_CHARS[x]; x++)
            valid = (str[i] == LABEL_CHARS[x]) ? true : valid;
        if (!valid)
            return (false);
    }
    return (true);
}

bool is_label(char *str)
{
    int len = my_strlen(str);
    bool valid = false;

    for (int i = 0; i < len - 1; i++) {
        for (int x = 0; LABEL_CHARS[x]; x++)
            valid = (str[i] == LABEL_CHARS[x]) ? true : valid;
        if (!valid)
            return (false);
    }
    if (str[len - 1] != LABEL_CHAR)
        return (false);
    return (true);
}

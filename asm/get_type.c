/*
** EPITECH PROJECT, 2022
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** get_type.c
*/

#include "corewar.h"

bool get_register(char *line)
{
    int len = my_strlen(line);

    if (line[0] == 'r' && len > 1 && len < 4 && is_digit(line, 1))
        return (true);
    return (false);
}

bool get_direct(char *line)
{
    if (line[0] == DIRECT_CHAR && my_strlen(line) > 1 && is_digit(line, 1))
        return (true);
    return (false);
}

bool get_indirect(char *line)
{
    if (my_strlen(line) > 0 && is_digit(line, 0))
        return (true);
    return (false);
}

bool get_label(char *line)
{
    if (line[0] == DIRECT_CHAR && line[1] == LABEL_CHAR
    && line[2] && check_label(line))
        return (true);
    return (false);
}

int get_type(char *line)
{
    if (get_direct(line))
        return (T_DIR);
    if (get_indirect(line))
        return (T_IND);
    if (get_register(line))
        return (T_REG);
    if (get_label(line))
        return (T_LAB);
    return (NONE);
}

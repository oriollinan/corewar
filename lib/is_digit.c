/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** is_digit
*/

#include "my_string.h"

bool is_digit(char *c, int pos)
{
    if (!c[pos])
        return (false);
    for (; c[pos]; pos++) {
        if (c[pos] < '0' || c[pos] > '9')
            return (false);
    }
    return (true);
}

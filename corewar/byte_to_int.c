/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** byte_to_int
*/

#include "corewar.h"

int four_to_int(char *str, int pos)
{
    int number = 0;

    for (int i = 0; i < 4; i++) {
        number <<= 8;
        number |= ((unsigned char)str[pos + i]) << (8 * (3 - i));
    }
    return (number);
}

int two_to_int(char *str, int pos)
{
    int number = 0;

    for (int i = 0; i < 2; i++) {
        number <<= 8;
        number |= ((unsigned char)str[pos + i]) << (8 * (1 - i));
    }
    return (number);
}

int byte_to_int(char *str, int pos, int bytes)
{
    if (bytes == 4)
        return (four_to_int(str, pos));
    if (bytes == 2)
        return (two_to_int(str, pos));
    if (bytes == 1)
        return ((unsigned char) str[pos]);
    return (0);
}

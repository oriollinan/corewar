/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** swap_endian
*/

#include "corewar.h"

int swap_four(int number)
{
    int byte0 = (number & 0x000000FF) >> 0;
    int byte1 = (number & 0x0000FF00) >> 8;
    int byte2 = (number & 0x00FF0000) >> 16;
    int byte3 = (number & 0xFF000000) >> 24;

    return ((byte0 << 24) | (byte1 << 16) | (byte2 << 8) | (byte3 << 0));
}

int swap_two(int number)
{
    int byte0 = (number & 0x000000FF) >> 0;
    int byte1 = (number & 0x0000FF00) >> 8;

    return ((byte0 << 8) | (byte1 << 0));
}

int swap_endian(int number, int size)
{
    if (size == 1)
        return (number);
    if (size == 2)
        return (swap_two(number));
    if (size == 4)
        return (swap_four(number));
    return (-1);
}

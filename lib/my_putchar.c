/*
** EPITECH PROJECT, 2022
** my_putchar
** File description:
** prints character yay
*/

#include "my_string.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

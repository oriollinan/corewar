/*
** EPITECH PROJECT, 2022
** core_war
** File description:
** my_memcpy.c
*/

#include "my_string.h"

void my_memcpy(void *dest, void *src, size_t n)
{
    char *dest_char = (char *) dest;
    char *src_char = (char *) src;

    for (int i = 0; i < n; i++)
        dest_char[i] = src_char[i];
}

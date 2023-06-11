/*
** EPITECH PROJECT, 2022
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** get_coding_byte.c
*/

#include "corewar.h"

void check_coding_type(int *coding_type, int tmp, int y, int i)
{
    if (tmp == (tmp & y) && tmp != 0 && coding_type[3 - i] == NONE_TYPE)
        coding_type[3 - i] = y;
}

int *get_coding_type(game_t *vm)
{
    int number = 0;
    unsigned char coding_byte = byte_to_int(vm->map, PC(vm), 1);
    int *coding_type = malloc(sizeof(int) * MAX_ARGS_NUMBER);
    unsigned char tmp = 0;

    if (!coding_type)
        return (NULL);
    for (int i = 0; i < MAX_ARGS_NUMBER; i++)
        coding_type[i] = NONE_TYPE;
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        tmp = coding_byte << (6 - (i * 2));
        tmp >>= 6;
        for (int y = 0; y < 4; y++)
            check_coding_type(coding_type, tmp, y, i);
    }
    return (coding_type);
}

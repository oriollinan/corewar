/*
** EPITECH PROJECT, 2022
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** live.c
*/

#include "corewar.h"

int live(body_t *body)
{
    if (!correct_type(body, 0))
        return (-1);
    body->size[0] = DIR_SIZE;
    for (int i = 1; i < MAX_ARGS_NUMBER; i++)
        body->size[i] = NONE;
    return (DIR_SIZE + OP_NAME);
}

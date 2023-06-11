/*
** EPITECH PROJECT, 2022
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** zjmp.c
*/

#include "corewar.h"

int zjmp(body_t *body)
{
    if (!correct_type(body, 8))
        return (-1);
    body->size[0] = IND_SIZE;
    for (int i = 1; i < MAX_ARGS_NUMBER; i++)
        body->size[i] = NONE;
    return (IND_SIZE + OP_NAME);
}

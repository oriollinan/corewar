/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** fork
*/

#include "corewar.h"

int fork_op(body_t *body)
{
    if (!correct_type(body, 11))
        return (-1);
    body->size[0] = IND_SIZE;
    for (int i = 1; i < MAX_ARGS_NUMBER; i++)
        body->size[i] = NONE;
    return (IND_SIZE + OP_NAME);
}

int lfork(body_t *body)
{
    if (!correct_type(body, 14))
        return (-1);
    body->size[0] = IND_SIZE;
    for (int i = 1; i < MAX_ARGS_NUMBER; i++)
        body->size[i] = NONE;
    return (IND_SIZE + OP_NAME);
}

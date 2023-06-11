/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** aff
*/

#include "corewar.h"

int aff(body_t *body)
{
    if (!correct_type(body, 15))
        return (-1);
    body->type[0] = R_SIZE;
    for (int i = 1; i < MAX_ARGS_NUMBER; i++)
        body->type[i] = NONE;
    return (R_SIZE + COD_BYTE + OP_NAME);
}

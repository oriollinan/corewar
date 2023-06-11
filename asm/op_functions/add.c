/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** add
*/

#include "corewar.h"

int add(body_t *body)
{
    if (!correct_type(body, 3))
        return (-1);
    for (int i = 0; i < 3; i++)
        body->size[i] = R_SIZE;
    body->size[3] = NONE;
    return ((R_SIZE * 3) + COD_BYTE + OP_NAME);
}

/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** ld
*/

#include "corewar.h"

int ld_op(body_t *body)
{
    if (!correct_type(body, 1))
        return (-1);
    body->size[0] = REG_SIZE;
    body->size[1] = R_SIZE;
    body->size[2] = NONE;
    body->size[3] = NONE;
    return (REG_SIZE + R_SIZE + COD_BYTE + OP_NAME);
}

int ldi(body_t *body)
{
    if (!correct_type(body, 9))
        return (-1);
    body->size[0] = REG_SIZE;
    body->size[1] = REG_SIZE;
    body->size[2] = R_SIZE;
    body->size[3] = NONE;
    return ((2 * REG_SIZE) + R_SIZE + COD_BYTE + OP_NAME);
}

int lld(body_t *body)
{
    if (!correct_type(body, 12))
        return (-1);
    body->size[0] = REG_SIZE;
    body->size[1] = R_SIZE;
    body->size[2] = NONE;
    body->size[3] = NONE;
    return (REG_SIZE + R_SIZE + COD_BYTE + OP_NAME);
}

int lldi(body_t *body)
{
    if (!correct_type(body, 13))
        return (-1);
    body->size[0] = REG_SIZE;
    body->size[1] = REG_SIZE;
    body->size[2] = R_SIZE;
    body->size[3] = NONE;
    return ((2 * REG_SIZE) + R_SIZE + COD_BYTE + OP_NAME);
}

/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** store_none
*/

#include "corewar.h"

void store_none(body_t *body, char *line, int j)
{
    body->type[j - 1] = NONE;
    body->arg[j - 1] = -1;
    body->label_name = NULL;
}

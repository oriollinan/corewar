/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** check_type
*/

#include "corewar.h"

int arg_amount(body_t *body)
{
    int amount = 0;

    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (body->type[i] != NONE)
            amount++;
    }
    return (amount);
}

bool correct_type(body_t *body, int nbr)
{
    int nbr_args = arg_amount(body);

    if (nbr_args != op_tab[nbr].nbr_args)
        return (false);
    for (int i = 0; i < nbr_args; i++) {
        if (body->type[i] == NONE)
            continue;
        if ((op_tab[nbr].type[i] & body->type[i]) == 0)
            return (false);
    }
    return (true);
}

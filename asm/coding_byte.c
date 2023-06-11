/*
** EPITECH PROJECT, 2022
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** coding_byte.c
*/

#include "corewar.h"

int type_cod_byte(int type)
{
    switch (type) {
    case (T_REG):
        return (T_REG);
    case (T_DIR):
        return (T_DIR);
    case (T_IND):
        return (3);
    case (T_LAB):
        return (2);
    case (NONE):
        return (NONE);
    }
}

bool has_coding_byte(char *op)
{
    char *ops[5] = {"live", "zjmp", "fork", "lfork", NULL};

    for (int j = 0; ops[j]; j++) {
        if (my_strcmp(ops[j], op) == 0)
            return (false);
    }
    return (true);
}

body_t *check_coding_byte(body_t *body)
{
    if (!has_coding_byte(body->op)) {
        body->coding_byte = '\0';
    } else {
        for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
            body->coding_byte = body->coding_byte << 2;
            body->coding_byte =
            (body->coding_byte | type_cod_byte(body->type[i]));
        }
    }
    return (body->next);
}

void get_coding_byte(body_t *body)
{
    while (body)
        body = check_coding_byte(body);
}

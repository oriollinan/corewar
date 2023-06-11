/*
** EPITECH PROJECT, 2022
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** store_instructions.c
*/

#include "corewar.h"

fptr_t fprt[TYPE_AMOUNT] = {
    {T_DIR, &store_direct},
    {T_REG, &store_register},
    {T_IND, &store_indirect},
    {T_LAB, &store_label}
};

void store_direct(body_t *body, char *line, int j)
{
    body->type[j - 1] = T_DIR;
    body->arg[j - 1] = my_getnbr(line);
}

void store_register(body_t *body, char *line, int j)
{
    body->type[j - 1] = T_REG;
    body->arg[j - 1] = my_getnbr(line);
}

void store_indirect(body_t *body, char *line, int j)
{
    body->type[j - 1] = T_IND;
    body->arg[j - 1] = my_getnbr(line);
}

void store_label(body_t *body, char *line, int j)
{
    body->type[j - 1] = T_LAB;
    body->arg[j - 1] = 0;
    body->label_name = malloc(sizeof(char) * my_strlen(line) - 1);

    if (!body->label_name)
        return;
    for (int i = 2, x = 0; line[i]; i++, x++)
        body->label_name[x] = line[i];
}

void store_instruction(body_t *body, int type, char **line, int j)
{
    for (int i = 0; i < TYPE_AMOUNT; i++) {
        if (type == fprt[i].type)
            fprt[i].func(body, line[j], j);
    }
}

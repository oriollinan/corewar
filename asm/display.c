/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** display
*/

#include "corewar.h"

FILE *open_file(char *name)
{
    FILE *file = NULL;
    int length = my_strlen(name);
    char *path = my_malloc_ini(sizeof(char) * (length + 2));

    name[length - 1] = '\0';
    path = my_strcat(path, name);
    path = my_strcat(path, "cor");
    file = fopen(path, "w");
    return (file);
}

void display_arg(body_t *body, FILE *file)
{
    int end_nbr = 0;

    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (body->type[i] != NONE) {
            end_nbr = swap_endian(body->arg[i], body->size[i]);
            fwrite(&end_nbr, body->size[i], 1, file);
        }
    }
}

void display(header_t *header, body_t *body, char *name)
{
    FILE *file = open_file(name);
    int op_nbr = 0;

    if (!file)
        return;
    if (header)
        fwrite(header, sizeof(header_t), 1, file);
    while (body) {
        op_nbr = get_op_nbr(&body->op) + 1;
        fwrite(&op_nbr, sizeof(char), 1, file);
        if (body->coding_byte)
            fwrite(&body->coding_byte, sizeof(char), 1, file);
        display_arg(body, file);
        body = body->next;
    }
    fclose(file);
}

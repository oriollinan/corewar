/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** get_progsize
*/

#include "corewar.h"

op_func_t func[MAX_OP] = {
    {"live", &live},
    {"ld", &ld_op},
    {"st", &st_op},
    {"add", &add},
    {"sub", &sub},
    {"and", &and_op},
    {"or", &or_op},
    {"xor", &xor_op},
    {"zjmp", &zjmp},
    {"ldi", &ldi},
    {"sti", &sti},
    {"fork", &fork_op},
    {"lld", &lld},
    {"lldi", &lldi},
    {"lfork", &lfork},
    {"aff", &aff},
    {"", NULL}
};

int get_args_size(body_t *body)
{
    int size = 0;

    for (int i = 0; i < MAX_OP; i++) {
        if (my_strcmp(body->op, func[i].op) == 0)
            size = func[i].func(body);
        if (size == -1)
            return (-1);
    }
    return (size);
}

bool get_prog_size(header_t *header, body_t *body)
{
    int prog_size = 0;
    int args = 0;

    while (body) {
        args = get_args_size(body);
        if (args != -1) {
            body->pc = prog_size;
            prog_size += args;
        } else
            return (false);
        body = body->next;
    }
    if (header)
        header->prog_size = swap_endian(prog_size, 4);
    return (true);
}

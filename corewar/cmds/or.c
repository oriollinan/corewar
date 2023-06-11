/*
** EPITECH PROJECT, 2022
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** or.c
*/

#include "corewar.h"

void logic_or(game_t *vm, int *coding_type, int instruction)
{
    int *type = malloc(sizeof(int) * op_tab[instruction].nbr_args);
    int *sizes = get_sizes(coding_type);
    int *params = NULL;

    type[0] = byte_to_int(vm->map, PC(vm), sizes[0]);
    vm->champion->pc += sizes[0];
    type[1] = byte_to_int(vm->map, PC(vm), sizes[1]);
    vm->champion->pc += sizes[1];
    type[2] = byte_to_int(vm->map, PC(vm), sizes[2]);
    params = get_params(vm, coding_type, type, instruction);
    vm->champion->pc += sizes[2];
    params[2] = params[1] & params[0];
    vm->champion->cooldown = op_tab[instruction].nbr_cycles;
    vm->carry = 1;
}

int or_cmd(game_t *vm)
{
    vm->champion->pc++;
    int *coding_type = get_coding_type(vm);
    vm->champion->pc++;
    if (!correct_operators_and(coding_type))
        return (1);
    logic_or(vm, coding_type, 7);
    return (0);
}

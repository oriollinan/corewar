/*
** EPITECH PROJECT, 2022
** core_war
** File description:
** ld.c
*/

#include "corewar.h"

bool correct_operators_ld(int *coding_byte)
{
    if ((coding_byte[0] == DIR_TYPE || coding_byte[0] == IND_TYPE) &&
    coding_byte[1] == REG_TYPE) {
        return (true);
    }
    return (false);
}

void logic_ld(game_t *vm, int *coding_type, int instruction)
{
    int *type = malloc (sizeof(int) * op_tab[instruction].nbr_args);
    int *sizes = get_sizes(coding_type);
    int *params = NULL;

    type[0] = byte_to_int(vm->map, PC(vm), sizes[0]);
    vm->champion->pc += sizes[0];
    type[1] = byte_to_int(vm->map, PC(vm), sizes[1]);
    vm->champion->pc += sizes[1];
    params = get_params(vm, coding_type, type, instruction);
    params[1] = PC(vm) + (params[0] % IDX_MOD);
    vm->champion->cooldown = op_tab[instruction].nbr_cycles;
    vm->carry = 1;
}

int ld_cmd(game_t *vm)
{
    vm->champion->pc++;
    int *coding_type = get_coding_type(vm);
    vm->champion->pc++;
    if (!correct_operators_ld(coding_type))
        return (1);
    logic_ld(vm, coding_type, 8);
    return (0);
}

void logic_lld(game_t *vm, int *coding_type, int instruction)
{
    int *type = malloc (sizeof(int) * op_tab[instruction].nbr_args);
    int *sizes = get_sizes(coding_type);
    int *params = NULL;

    type[0] = byte_to_int(vm->map, PC(vm), sizes[0]);
    vm->champion->pc += sizes[0];
    type[1] = byte_to_int(vm->map, PC(vm), sizes[1]);
    vm->champion->pc += sizes[1];
    params = get_params(vm, coding_type, type, instruction);
    params[1] = PC(vm) + (params[0]);
    vm->champion->cooldown = op_tab[instruction].nbr_cycles;
    vm->carry = 1;
}

int lld_cmd(game_t *vm)
{
    vm->champion->pc++;
    int *coding_type = get_coding_type(vm);
    vm->champion->pc++;
    if (!correct_operators_ld(coding_type))
        return (1);
    logic_lld(vm, coding_type, 8);
    return (0);
}

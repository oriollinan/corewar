/*
** EPITECH PROJECT, 2023
** sti
** File description:
** sti command
*/

#include "corewar.h"

bool correct_operators_sti(int *coding_byte)
{
    if (coding_byte[0] == REG_TYPE && coding_byte[1] != NONE &&
        coding_byte[2] != NONE && coding_byte[2] != IND_TYPE) {
        return (true);
    }
    return (false);
}

int *get_sizes_st(int *coding_type)
{
    int *sizes = malloc(sizeof(int) * MAX_ARGS_NUMBER);
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        switch (coding_type[i]) {
        case REG_TYPE:
            sizes[i] = REG_SIZE;
            break;
        case DIR_TYPE:
            sizes[i] = T_DIR;
            break;
        case IND_TYPE:
            sizes[i] = IND_SIZE;
            break;
        case NONE_TYPE:
            sizes[i] = NONE;
            break;
        default:
            break;
        }
    }
    return (sizes);
}

void logic_sti(game_t *vm, int *coding_type, int instruction)
{
    int *type = malloc(sizeof(int) * op_tab[instruction].nbr_args);
    int *sizes = get_sizes_st(coding_type);
    int *params = NULL;

    type[0] = byte_to_int(vm->map, PC(vm), sizes[0]);
    vm->champion->pc += sizes[0];
    type[1] = byte_to_int(vm->map, PC(vm), sizes[1]);
    vm->champion->pc += sizes[1];
    type[2] = byte_to_int(vm->map, PC(vm), sizes[2]);
    params = get_params(vm, coding_type, type, instruction);
    vm->champion->pc += sizes[2];
    vm->map[PC(vm) + ((params[1] + params[2]) % IDX_MOD)] = params[0];
    vm->champion->cooldown = op_tab[instruction].nbr_cycles;
    vm->carry = 1;
}

int sti_cmd(game_t *vm)
{
    int test = vm->champion->pc;
    vm->champion->pc++;
    int *coding_type = get_coding_type(vm);
    vm->champion->pc++;
    if (!correct_operators_sti(coding_type)) {
        return (1);
    }
    logic_sti(vm, coding_type, 11);
    vm->champion->pc = test + 7;
    return (0);
}

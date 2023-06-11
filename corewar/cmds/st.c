/*
** EPITECH PROJECT, 2022
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** st.c
*/

#include "corewar.h"

bool correct_operators_st(int *coding_byte)
{
    if (coding_byte[0] == REG_TYPE && (coding_byte[1] == REG_TYPE ||
        coding_byte[1] == IND_TYPE)) {
        return (true);
    }
    return (false);
}

void logic_st(game_t *vm, int *coding_type, int instruction)
{
    int *type = malloc(sizeof(int) * op_tab[instruction].nbr_args);
    int *sizes = get_sizes_st(coding_type);
    int *params = NULL;

    type[0] = byte_to_int(vm->map, PC(vm), sizes[0]);
    vm->champion->pc += sizes[0];
    type[1] = byte_to_int(vm->map, PC(vm), sizes[1]);
    vm->champion->pc += sizes[1];
    params = get_params(vm, coding_type, type, instruction);
    vm->map[PC(vm) + ((params[1]) % IDX_MOD)] = params[0];
    vm->champion->cooldown = op_tab[instruction].nbr_cycles;
    vm->carry = 1;
}

int st_cmd(game_t *vm)
{
    vm->champion->pc++;
    int *coding_type = get_coding_type(vm);
    vm->champion->pc++;
    if (!correct_operators_st(coding_type))
        return (1);
    logic_st(vm, coding_type, 3);
    return (0);
}

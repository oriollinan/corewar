/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** and
*/

#include "corewar.h"

bool correct_operators_and(int *coding_byte)
{
    if (coding_byte[0] != NONE && coding_byte[1] != NONE &&
        coding_byte[2] == REG_TYPE && coding_byte[3] == NONE) {
        return (true);
    }
    return (false);
}

int *get_sizes(int *coding_type)
{
    int *sizes = malloc(sizeof(int) * MAX_ARGS_NUMBER);
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        switch (coding_type[i]) {
        case REG_TYPE:
            sizes[i] = REG_SIZE;
            break;
        case DIR_TYPE:
            sizes[i] = DIR_SIZE;
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

int *get_params(game_t *vm, int *coding_type, int *type, int instruction)
{
    int *params = malloc(sizeof(int) * MAX_ARGS_NUMBER);
    for (int i = 0; i < op_tab[instruction].nbr_args; i++) {
        switch (coding_type[i]){
        case REG_TYPE:
            params[i] = vm->r[type[i] - 1];
            break;
        case DIR_TYPE:
            params[i] = type[i];
            break;
        case IND_TYPE:
            params[i] = type[i];
            break;
        case NONE_TYPE:
            params[i] = -1;
            break;
        default:
            break;
        }
    }
    return (params);
}

void logic_and(game_t *vm, int *coding_type, int instruction)
{
    int *type = malloc(sizeof(int) * op_tab[6].nbr_args);
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

int and_cmd(game_t *vm)
{
    vm->champion->pc++;
    int *coding_type = get_coding_type(vm);
    vm->champion->pc++;
    if (!correct_operators_and(coding_type))
        return (1);
    logic_and(vm, coding_type, 6);
    return (0);
}

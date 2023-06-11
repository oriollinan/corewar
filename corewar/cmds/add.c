/*
** EPITECH PROJECT, 2023
** core_war
** File description:
** add
*/

#include "corewar.h"

void logic_add(game_t *vm, int *reg1, int *reg2, int *reg3)
{
    (*reg1) = byte_to_int(vm->map, PC(vm), REG_SIZE);
    vm->champion->pc += REG_SIZE;
    (*reg2) = byte_to_int(vm->map, PC(vm), REG_SIZE);
    vm->champion->pc += REG_SIZE;
    (*reg3) = byte_to_int(vm->map, PC(vm), REG_SIZE);
    vm->champion->pc += REG_SIZE;
    vm->r[(*reg3)] = vm->r[(*reg1)] + vm->r[(*reg2)];
    vm->champion->cooldown = 10;
    vm->carry = 1;
}

int add_cmd(game_t *vm)
{
    int reg1 = 0;
    int reg2 = 0;
    int reg3 = 0;
    int *coding_byte = NULL;

    vm->champion->pc++;
    coding_byte = get_coding_type(vm);
    vm->champion->pc++;
    for (int i = 0; i < 3; i++) {
        if (coding_byte[i] != REG_TYPE) {
            vm->champion->pc += REG_SIZE;
            vm->champion->cooldown = 10;
            vm->carry = 0;
            return (1);
        }
    }
    logic_add(vm, &reg1, &reg2, &reg3);
    return (0);
}

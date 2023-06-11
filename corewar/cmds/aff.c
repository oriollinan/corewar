/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** aff
*/

#include "corewar.h"

int aff_regis_err(game_t *vm, int reg)
{
    if (reg > 16) {
        vm->champion->pc += REG_SIZE;
        vm->champion->cooldown = 2;
        return (1);
    }
    return (0);
}

int aff_cmd(game_t *vm)
{
    char value = 0;
    vm->champion->pc++;
    int *coding_byte = get_coding_type(vm);
    if (coding_byte[0] != REG_TYPE) {
        vm->champion->pc += REG_SIZE + 1;
        vm->champion->cooldown = 2;
        return (1);
    }
    vm->champion->pc++;
    int reg = byte_to_int(vm->map, PC(vm), REG_SIZE);
    if (aff_regis_err(vm, reg) == 1) return (1);
    vm->champion->pc += REG_SIZE;
    value = vm->r[reg - 1];
    write(1, &value, 1);
    my_putchar('\n');
    vm->champion->cooldown = 2;
    return (0);
}

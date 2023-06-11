/*
** EPITECH PROJECT, 2022
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** zjmp.c
*/

#include "corewar.h"

int zjmp_cmd(game_t *vm)
{
    vm->champion->pc++;
    int index = byte_to_int(vm->map, PC(vm), IND_SIZE);
    vm->champion->pc += IND_SIZE;
    if (vm->carry == 1) {
        vm->champion->pc += index % IDX_MOD;
    }
    vm->champion->cooldown = 20;
    return (0);
}

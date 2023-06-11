/*
** EPITECH PROJECT, 2022
** core_war
** File description:
** ldi.c
*/

#include "corewar.h"

int ldi_regis_error(int *coding_byte, game_t *vm, int param, int i)
{
    if (coding_byte[i] == REG_TYPE && param > 16) {
        vm->champion->pc += REG_SIZE;
        vm->carry = 0;
        return (1);
    }
    return (0);
}

int ldi_error(int *coding_byte, game_t *vm)
{
    if ((coding_byte[0] != REG_TYPE && coding_byte[0] != IND_TYPE) ||
    (coding_byte[1] != REG_TYPE && coding_byte[1] != IND_TYPE)) {
        vm->champion->pc += (coding_byte[0] == IND_TYPE || coding_byte[1]
        == IND_TYPE) ? (REG_SIZE * 2 + IND_SIZE + 1) : (REG_SIZE * 3 + 1);
        return 1;
    }
    if (coding_byte[2] != REG_TYPE) {
        vm->champion->pc += (coding_byte[0] == IND_TYPE ? IND_SIZE : REG_SIZE)
        + (coding_byte[1] == IND_TYPE ? IND_SIZE : REG_SIZE) + REG_SIZE + 1;
        return 1;
    }
    return 0;
}

void get_param_ldi(int *coding_byte, int *param1, int *param2, game_t *vm)
{
    if (coding_byte[0] == REG_TYPE) {
        (*param1) = byte_to_int(vm->map, PC(vm), REG_SIZE);
        (*param1) = vm->r[(*param1) - 1];
        vm->champion->pc += REG_SIZE;
    } else {
        (*param1) = byte_to_int(vm->map, PC(vm), IND_SIZE);
        vm->champion->pc += IND_SIZE;
    }
    if (coding_byte[1] == REG_TYPE) {
        (*param2) = byte_to_int(vm->map, PC(vm), REG_SIZE);
        (*param2) = vm->r[(*param2) - 1];
        vm->champion->pc += REG_SIZE;
    } else {
        (*param2) = byte_to_int(vm->map, PC(vm), IND_SIZE);
        vm->champion->pc += IND_SIZE;
    }

}

int ldi_cmd(game_t *vm)
{
    int param1 = 0, param2 = 0, param3 = 0, s = 0;
    vm->champion->pc++;
    int *coding_byte = get_coding_type(vm);
    if (ldi_error(coding_byte, vm) == 1) {
        vm->carry = 0;
        vm->champion->cooldown = 25;
        return (1);
    }
    get_param_ldi(coding_byte, &param1, &param2, vm);
    param3 = byte_to_int(vm->map, PC(vm), REG_SIZE);
    vm->champion->pc += REG_SIZE;
    s = vm->map[PC(vm) + param1 % IDX_MOD] + param2;
    vm->r[param3 - 1] = vm->map[PC(vm) + s % IDX_MOD];
    vm->champion->cooldown = 25;
    vm->carry = 1;
    return (0);
}

int lldi_cmd(game_t *vm)
{
    int param1 = 0, param2 = 0, param3 = 0, s = 0;
    vm->champion->pc++;
    int *coding_byte = get_coding_type(vm);
    if (ldi_error(coding_byte, vm) == 1) {
        vm->carry = 0;
        vm->champion->cooldown = 50;
        return (1);
    } get_param_ldi(coding_byte, &param1, &param2, vm);
    param3 = byte_to_int(vm->map, PC(vm), REG_SIZE);
    if (ldi_regis_error(coding_byte, vm, param1, 0) == 1 ||
    ldi_regis_error(coding_byte, vm, param2, 1) == 1 ||
    ldi_regis_error(coding_byte, vm, param3, 3) == 1) {
        vm->champion->cooldown = 50;
        return (1);
    } vm->champion->pc += REG_SIZE;
    s = vm->map[PC(vm) + param1] + param2;
    vm->r[param3 - 1] = vm->map[PC(vm) + s];
    vm->champion->cooldown = 50;
    vm->carry = 1;
    return (0);
}

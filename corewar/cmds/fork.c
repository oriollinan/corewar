/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** fork
*/

#include "corewar.h"

void create_lfork(game_t *vm)
{
    champion_t *tmp = init_champion();

    my_memcpy(tmp, vm->champion, sizeof(champion_t));
    vm->champion = go_last_elem(vm->champion);
    vm->champion->next = tmp;
    tmp->prev = vm->champion;
    vm->champion = go_first_elem(vm->champion);
    sort_champlist(&vm->champion);
    tmp->load_address = PC(vm) + tmp->f_index;
    for (int i = 0; i < tmp->prog_size; i++)
        vm->map[(PC(vm) + tmp->f_index) + i] = tmp->program[i];
}

void create_fork(game_t *vm)
{
    champion_t *tmp = init_champion();

    my_memcpy(tmp, vm->champion, sizeof(champion_t));
    vm->champion = go_last_elem(vm->champion);
    vm->champion->next = tmp;
    tmp->prev = vm->champion;
    vm->champion = go_first_elem(vm->champion);
    sort_champlist(&vm->champion);
    tmp->load_address = PC(vm) + tmp->f_index % IDX_MOD;
    for (int i = 0; i < tmp->prog_size; i++)
        vm->map[(PC(vm) + tmp->f_index % IDX_MOD) + i] = tmp->program[i];
}

void check_fork(game_t *vm)
{
    if (vm->champion->fork && vm->champion->f_count == 800) {
        create_fork(vm);
        vm->champion->fork = false;
        vm->champion->f_count = 0;
        return;
    }
    if (vm->champion->lfork && vm->champion->f_count == 1000) {
        create_lfork(vm);
        vm->champion->lfork = false;
        vm->champion->f_count = 0;
        return;
    }
    if (vm->champion->fork) {
        vm->champion->f_count++;
        return;
    }
    if (vm->champion->lfork) {
        vm->champion->f_count++;
        return;
    }
}

int fork_cmd(game_t *vm)
{
    vm->champion->pc++;
    int index = byte_to_int(vm->map, PC(vm), IND_SIZE);
    vm->champion->fork = true;
    vm->champion->f_index = index;
    vm->champion->cooldown = 800;
    vm->champion->pc += IND_SIZE;
    return (0);
}

int lfork_cmd(game_t *vm)
{
    vm->champion->pc++;
    int index = byte_to_int(vm->map, PC(vm), IND_SIZE);
    vm->champion->lfork = true;
    vm->champion->f_index = index;
    vm->champion->cooldown = 1000;
    vm->champion->pc += IND_SIZE;
    return (0);
}

/*
** EPITECH PROJECT, 2023
** core_war
** File description:
** check_cycle
*/

#include "corewar.h"

champion_t *check_live(champion_t *champlist)
{
    while (champlist) {
        if (!champlist->live)
            champlist = delete_node(champlist);
        else {
            champlist->live = false;
            champlist = champlist->next;
        }
    }
    return (champlist);
}

int check_cycle(game_t *vm, int *cycle)
{
    static int cycle_die = CYCLE_TO_DIE;

    if (*cycle == cycle_die) {
        vm->champion = check_live(vm->champion);
        cycle_die -= CYCLE_DELTA;
        (*cycle) = 0;
    }
    if ((vm->champion && (!vm->champion->prev && !vm->champion->next))
    || cycle_die <= 0)
        return (1);
    if (*cycle == vm->dump) {
        dump_memory(vm);
        return (1);
    }
    return (0);
}

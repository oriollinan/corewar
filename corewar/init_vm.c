/*
** EPITECH PROJECT, 2022
** core_war
** File description:
** init_vm.c
*/

#include "corewar.h"

bool check_free_nb(champion_t *champlist, int *nbr)
{
    champion_t *tmp = champlist;
    tmp = go_first_elem(tmp);

    while (tmp->next) {
        if (tmp->prog_nbr == (*nbr))
            return (false);
        tmp = tmp->next;
    }
    if (tmp->prog_nbr == (*nbr))
        return (false);
    return (true);
}

void cond_check_nbr(champion_t *tmp, int *prog_nb_def)
{
    while (!check_free_nb(tmp, prog_nb_def)) {
        (*prog_nb_def)++;
    }
}

champion_t *put_prog_nb(game_t *vm)
{
    champion_t *tmp = vm->champion;
    int prog_nb_def = 1;
    tmp = go_first_elem(tmp);

    while (tmp->next) {
        if (tmp->prog_nbr == -1) {
            cond_check_nbr(tmp, &prog_nb_def);
            tmp->prog_nbr = prog_nb_def;
        }
            tmp = tmp->next;
    }
    if (tmp->prog_nbr == -1) {
        while (!check_free_nb(tmp, &prog_nb_def)) {
            prog_nb_def++;
        }
        tmp->prog_nbr = prog_nb_def;
    }
    tmp = go_first_elem(tmp);
}

void display_prog_nbr(champion_t *list)
{
    champion_t *champlist = list;

    while (champlist->next) {
        champlist = champlist->next;
    }
}

game_t *init_vm(char **argv)
{
    game_t *vm = malloc(sizeof(game_t));

    if (!vm)
        return (NULL);
    vm->map = my_malloc_ini(MEM_SIZE - 1);
    if (!vm->map)
        return (NULL);
    vm->carry = 0;
    vm->dump = my_getnbr(argv[2]);
    for (int i = 0; i < REG_NUMBER; i++)
        vm->r[i] = 0;
    vm->champion = NULL;
    vm->last_live = NULL;
    init_champlist(argv, vm);
    vm->champion = put_prog_nb(vm);
    display_prog_nbr(vm->champion);
    sort_champlist(&vm->champion);
    display_prog_nbr(vm->champion);
    return (vm);
}

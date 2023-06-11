/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** main
*/

#include "corewar.h"

cmd_t cmds[MAX_OP] = {
    {1, &live_cmd},
    {2, &ld_cmd},
    {3, &st_cmd},
    {4, &add_cmd},
    {5, &sub_cmd},
    {6, &and_cmd},
    {7, &or_cmd},
    {8, &xor_cmd},
    {9, &zjmp_cmd},
    {10, &ldi_cmd},
    {11, &sti_cmd},
    {12, &fork_cmd},
    {13, &lld_cmd},
    {14, &lldi_cmd},
    {15, &lfork_cmd},
    {16, &aff_cmd},
    {17, NULL},
};

void check_cooldown(game_t *vm)
{
    while (vm->champion && vm->champion->cooldown != 0) {
        check_fork(vm);
        vm->champion->cooldown -= 1;
        if (!vm->champion->next)
            break;
        vm->champion = vm->champion->next;
    }
}

void find_cmd(game_t *vm)
{
    int i = 0;
    int ret = -1;

    while (i < MAX_OP) {
        if (vm->map[PC(vm)] == cmds[i].type)
            ret = cmds[i].func(vm);
        i++;
    }
    if (ret == -1)
        vm->champion->pc++;
    if (vm->champion->pc >= vm->champion->prog_size - 1)
        vm->champion->pc = sizeof(header_t);
}

void run_cmd(game_t *vm)
{
    while (1) {
        check_cooldown(vm);
        if (!vm->champion)
            break;
        if (vm->champion->cooldown == 0)
            find_cmd(vm);
        if (!vm->champion->next)
            break;
    }
}

void main_loop(game_t *vm)
{
    int cycle = 0;

    while (1) {
        if (check_cycle(vm, &cycle) == 1)
            break;
        run_cmd(vm);
        if (vm->champion)
            vm->champion = go_first_elem(vm->champion);
        cycle++;
    }
}

int main(int argc, char **argv)
{
    game_t *vm = NULL;

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        display_help();
        return (0);
    }
    if (argc < 4 || my_strcmp(argv[1], "-dump") != 0)
        return (84);
    vm = init_vm(argv);
    if (!vm)
        return (84);
    create_map(vm);
    main_loop(vm);
    return (0);
}

/*
** EPITECH PROJECT, 2022
** core_war
** File description:
** execute_cmd.c
*/

#include "corewar.h"

champion_t *find_by_number(champion_t *champion, int number)
{
    while (champion) {
        if (champion->prog_nbr == number)
            return (champion);
        champion = champion->next;
    }
    return (NULL);
}

void assign_last_live(game_t *vm)
{
    champion_t *champ = init_champion();

    if (vm->last_live)
        free(vm->last_live);
    my_memcpy(champ, vm->champion, sizeof(champion_t));
    vm->last_live = champ;
}

int live_cmd(game_t *vm)
{
    vm->champion->pc++;
    int number = byte_to_int(vm->map, PC(vm), 4);
    champion_t *champ = find_by_number(go_first_elem(vm->champion), number);

    if (champ) {
        write(1, "The Player ", 11);
        my_put_nbr(number);
        write(1, "(", 1);
        write(1, champ->prog_name, my_strlen(champ->prog_name));
        write(1, ")is alive.\n", 11);
        champ->live = true;
    }
    vm->champion->cooldown = 10;
    vm->champion->pc += 4;
    assign_last_live(vm);
    return (0);
}

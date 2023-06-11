/*
** EPITECH PROJECT, 2022
** core_war
** File description:
** create_map.c
*/

#include "corewar.h"

int fill_map(champion_t *champion, char *map, int j, int spaces)
{
    for (int a = 0; a < champion->prog_size; a++) {
        map[j] = champion->program[a];
        if (a < MEM_SIZE)
            j += 1;
        else
            j = 0;
    }
    for (int b = 0; b < spaces - champion->prog_size && j < MEM_SIZE; b++) {
        map[j] = '\0';
        j += 1;
    }
    return (j);
}

void create_map(game_t *vm)
{
    champion_t *tmp = vm->champion;
    int i = 0;
    int j = 0;
    int spaces = 0;

    while (tmp) {
        i++;
        tmp = tmp->next;
    }
    tmp = vm->champion;
    spaces = MEM_SIZE / (i + 1);
    while (tmp) {
        tmp->load_address = j;
        j = fill_map(tmp, vm->map, j, spaces);
        tmp = tmp->next;
    }
}

/*
** EPITECH PROJECT, 2023
** init_champlist.c
** File description:
** function utils to initialize champion's linkedlist
*/

#include "corewar.h"

void condition_flags(champion_t *champlist, char **argv, int *i)
{
    if (my_strcmp(argv[(*i)], "-n") == 0) {
        (*i)++;
        champlist->prog_nbr = my_getnbr(argv[(*i)]);
        (*i)++;
    }
    if (my_strcmp(argv[(*i)], "-a") == 0) {
        (*i)++;
        champlist->load_address = my_getnbr(argv[(*i)]);
        (*i)++;
    }
}

champion_t *init_champion(void)
{
    champion_t *champion = malloc(sizeof(champion_t));
    if (!champion)
        return (NULL);
    champion->prog_nbr = -1;
    champion->load_address = 0;
    champion->cooldown = 0;
    champion->prog_size = 0;
    champion->f_index = 0;
    champion->f_count = 0;
    champion->pc = sizeof(header_t);
    champion->live = false;
    champion->fork = false;
    champion->lfork = false;
    champion->prog_name = NULL;
    champion->program = NULL;
    champion->next = NULL;
    champion->prev = NULL;
    return (champion);
}

champion_t *fill_list(champion_t *champlist, char **argv, int *i)
{
    champion_t *new = init_champion();

    if (!new)
        return (NULL);
    condition_flags(new, argv, i);
    new->prog_name = my_malloc_ini(my_strlen(argv[(*i)]));
    new->prog_name = my_strcpy(new->prog_name, argv[(*i)]);
    new->prog_size = count_bytes(new->prog_name);
    new->program = read_file(new->prog_name, new->prog_size);
    (*i++);
    if (!champlist)
        champlist = new;
    else {
        champlist->next = new;
        new->prev = champlist;
    }
    return (new);
}

void init_champlist(char **argv, game_t *vm)
{
    for (int i = 3; argv[i]; i++)
        vm->champion = fill_list(vm->champion, argv, &i);
    vm->champion = go_first_elem(vm->champion);
}

/*
** EPITECH PROJECT, 2023
** manage_list
** File description:
** function utils to manage linkedlists
*/

#include "corewar.h"

champion_t *delete_node(champion_t *champlist)
{
    champion_t *champ = go_first_elem(champlist);

    if (champ == champlist)
        champ = champ->next;
    if (champlist->prev)
        champlist->prev->next = NULL;
    if (champlist->next)
        champlist->next->prev = NULL;
    free(champlist);
    return (champ);
}

champion_t *go_first_elem(champion_t *champlist)
{
    while (champlist->prev) {
        champlist = champlist->prev;
    }
    return (champlist);
}

champion_t *go_last_elem(champion_t *champlist)
{
    while (champlist->next) {
        champlist = champlist->next;
    }
    return (champlist);
}

int my_list_len(champion_t *champlist)
{
    int ret = 0;

    champlist = go_first_elem(champlist);
    while (champlist->next) {
        ret++;
        champlist = champlist->next;
    }
    ret++;
    champlist = go_first_elem(champlist);
    return (ret);
}

/*
** EPITECH PROJECT, 2023
** sort_champlist
** File description:
** function util to sort champlist by program number
*/

#include "corewar.h"

champion_t *set_aux_prev(champion_t *aux_prev, champion_t *tmp)
{
    while (aux_prev != tmp)
        aux_prev = aux_prev->next;
    return (aux_prev);
}

champion_t *swap_nodeschamp(champion_t **head_list,
champion_t *tmp, bool *modified)
{
    champion_t *aux = NULL;
    champion_t *aux_prev = NULL;

    if (tmp->prog_nbr > tmp->next->prog_nbr) {
        aux = tmp->next;
        tmp->next = aux->next;
        aux->next = tmp;
        if (tmp == (*head_list))
            (*head_list) = aux;
        else {
            aux_prev = (*head_list);
            aux_prev = set_aux_prev(aux_prev, tmp);
            aux_prev->next = aux;
        }
        tmp = aux;
        (*modified) = true;
    }
    return (tmp);
}

void sort_champlist(champion_t **head_list)
{
    bool modified = true;
    champion_t *tmp = NULL;
    champion_t *tail_list = NULL;

    if (!(*head_list) || !(*head_list)->next)
        return;

    while (modified) {
        modified = false;
        tmp = (*head_list);

        while (tmp->next != tail_list) {
            tmp = swap_nodeschamp(head_list, tmp, &modified);
            tmp = tmp->next;
        }
        tail_list = tmp;
    }
}

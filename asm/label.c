/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** label
*/

#include "corewar.h"

int get_label_pos(char **arr, char *label)
{
    char **split = NULL;
    int len = my_strlen(label);
    char *label_name = malloc(sizeof(char) * (len + 2));

    for (int j = 0; arr[j]; j++) {
        split = my_new_split(arr[j], "\t ");
        my_strcpy(label_name, label);
        my_strcat(label_name, ":");
        if (my_strcmp(split[0], label_name) == 0)
            return (j - 2);
        free_arr(split);
    }
    return (-1);
}

int get_label_pc(body_t *body, int i, int current_pc)
{
    while (body && i > 0) {
        if (body->next)
            body = body->next;
        else
            break;
        i--;
    }
    if (body)
        return (body->pc - current_pc);
    return (-1);
}

void store_label_pc(body_t *body, int pc)
{
    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (body->type[i] == T_LAB) {
            body->arg[i] = pc;
        }
    }
}

void label_pos(body_t *head, char **arr)
{
    int pos = 0;
    int pc = 0;
    body_t *body = head;

    while (body) {
        if (body->label_name) {
            pos = get_label_pos(arr, body->label_name);
            pc = get_label_pc(head, pos, body->pc);
            store_label_pc(body, pc);
        }
        body = body->next;
    }
}

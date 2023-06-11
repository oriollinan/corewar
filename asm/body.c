/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** body
*/

#include "corewar.h"

int get_op_nbr(char **line)
{
    for (int j = 0; j < MAX_OP; j++) {
        if (my_strcmp(op_tab[j].mnemonique, line[0]) == 0)
            return (j);
    }
    return (-1);
}

body_t *get_last(body_t *head)
{
    while (head->next)
        head = head->next;
    return (head);
}

body_t *get_instruction(char **line, body_t *head)
{
    body_t *body = malloc(sizeof(body_t));
    int type = 0;

    if (!body)
        return (NULL);
    body->op = line[0];
    body->next = NULL;
    for (int j = 1; j <= MAX_ARGS_NUMBER; j++)
        store_none(body, NULL, j);
    for (int j = 1; line[j]; j++) {
        type = get_type(line[j]);
        store_instruction(body, type, line, j);
    }
    if (!head)
        head = body;
    else
        get_last(head)->next = body;
    return (head);
}

char **skip_label(char **line)
{
    if (is_label(line[0])) {
        if (my_arrlen(line) == 1)
            return (NULL);
        return (line++, line++);
    }
    return (line);
}

body_t *get_body(header_t *header, char **arr)
{
    body_t *head = NULL;
    char **line = NULL;
    bool next_line = false;

    for (int j = 0; arr[j]; j++) {
        line = my_new_split(arr[j], " \t,");
        if (!line)
            return (NULL_2);
        line = skip_label(line);
        if (!line)
            continue;
        if (get_op_nbr(line) != -1 &&
        (head = get_instruction(line, head)) == NULL)
            return (NULL_2);
    }
    if (!get_prog_size(header, head))
        return (NULL_2);
    get_coding_byte(head);
    label_pos(head, arr);
    return (head);
}

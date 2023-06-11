/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** main
*/

#include "corewar.h"

int main(int ac, char **av)
{
    char **arr = get_asm(ac, av);
    header_t *header = NULL;
    body_t *body = NULL;

    if (!arr)
        return (84);
    header = get_header(arr);
    body = get_body(header, arr);
    if (body == NULL_2)
        return (84);
    display(header, body, av[1]);
    return (0);
}

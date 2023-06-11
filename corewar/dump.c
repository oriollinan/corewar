/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** dump
*/

#include "corewar.h"

void display_line_number(int i)
{
    int max_len = my_intlen(MEM_SIZE);
    char *line_hex = dec_to_base(16, i, 0);

    write(1, line_hex, my_strlen(line_hex));
    for (int x = my_strlen(line_hex); x < max_len; x++)
        write(1, " ", 1);
    free(line_hex);
    write(1, " : ", 3);
}

void display_memory(char *str, int i)
{
    if (i % 32 == 0) {
        if (i != 0)
            write(1, "\n", 1);
        display_line_number(i);
        write(1, str, my_strlen(str));
        write(1, " ", 1);
    } else {
        write(1, str, my_strlen(str));
        if (i != MEM_SIZE - 1 && i % 32 != 31)
            write(1, " ", 1);
    }

}

void dump_memory(game_t *vm)
{
    char *str = NULL;
    int num = 0;

    for (int i = 0; i < MEM_SIZE; i++) {
        num = byte_to_int(vm->map, i, 1);
        str = dec_to_base(16, num, 2);
        display_memory(str, i);
        free(str);
    }
    write(1, "\n", 1);
}

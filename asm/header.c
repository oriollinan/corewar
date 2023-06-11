/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** header
*/

#include "corewar.h"

void get_name(header_t *header, char **lines)
{
    int x = 0;

    for (int j = 1; lines[j]; j++) {
        for (int i = 0; lines[j][i]; i++) {
            header->prog_name[x] = lines[j][i];
            x++;
        }
    }
    while (x < PROG_NAME_LENGTH) {
        header->prog_name[x] = '\0';
        x++;
    }
}

void get_comment(header_t *header, char **lines)
{
    int x = 0;

    for (int j = 1; lines[j] && x < COMMENT_LENGTH; j++) {
        for (int i = 0; lines[j][i] && x < COMMENT_LENGTH; i++) {
            header->comment[x] = lines[j][i];
            x++;
        }
    }
    while (x < COMMENT_LENGTH) {
        header->comment[x] = '\0';
        x++;
    }
}

void get_info(header_t *header, char **arr)
{
    char **lines = NULL;

    for (int j = 0; arr[j]; j++) {
        lines = my_new_split(arr[j], "\"");
        if (my_strstr(lines[0], NAME_CMD_STRING))
            get_name(header, lines);
        if (my_strstr(lines[0], COMMENT_CMD_STRING))
            get_comment(header, lines);
        free_arr(lines);
    }
}

header_t *get_header(char **arr)
{
    header_t *header = malloc(sizeof(header_t));

    if (!header)
        return (NULL);
    header->magic = swap_endian(COREWAR_EXEC_MAGIC, 4);
    header->prog_size = 0;
    get_info(header, arr);
    return (header);
}

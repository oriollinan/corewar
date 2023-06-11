/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-corewar-alba.candelario-matas
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include "my_string.h"

    #include "my_arr.h"
    #include "my_num.h"
    #include "op.h"

    #define TYPE_AMOUNT 4
    #define MAX_OP 17
    #define NONE 0
    #define R_SIZE 1
    #define COD_BYTE 1
    #define OP_NAME 1
    #define NULL_2 ((void *)1)
    #define PC(vm) vm->champion->load_address + vm->champion->pc
    #define REG_TYPE 1
    #define DIR_TYPE 2
    #define IND_TYPE 3
    #define NONE_TYPE 0

    typedef struct body_s {
        char *op;
        char coding_byte;
        int type[4];
        int size[MAX_ARGS_NUMBER];
        int arg[MAX_ARGS_NUMBER];
        char *label_name;
        int pc;
        struct body_s *next;
    } body_t;

    typedef struct fptr_s {
        int type;
        void (*func)(body_t *, char *, int j);
    } fptr_t;

    typedef struct champion_s {
        int prog_nbr;
        int load_address;
        char *prog_name;
        char *program;
        int prog_size;
        int pc;
        int cooldown;
        bool live;
        bool fork;
        bool lfork;
        int f_index;
        int f_count;
        struct champion_s *next;
        struct champion_s *prev;
    } champion_t;

    typedef struct game_s {
        char *map;
        int r[REG_NUMBER];
        int carry;
        int dump;
        champion_t *champion;
        champion_t *last_live;
    } game_t;

    typedef struct cmd_s {
        char type;
        int (*func)(game_t *);
    } cmd_t;

    typedef struct op_func_s {
        char *op;
        int (*func)(body_t *);
    } op_func_t;

    char **get_asm(int ac, char **av);
    char *read_file(char *path, int size);
    header_t *get_header(char **arr);
    body_t *get_body(header_t *header, char **arr);
    void store_direct(body_t *body, char *line, int j);
    void store_indirect(body_t *body, char *line, int j);
    void store_register(body_t *body, char *line, int j);
    void store_label(body_t *body, char *line, int j);
    void store_none(body_t *body, char *line, int j);
    void store_instruction(body_t *body, int type, char **line, int j);
    int get_type(char *line);
    bool get_prog_size(header_t *header, body_t *body);
    int get_op_nbr(char **line);
    int swap_endian(int number, int size);
    void get_coding_byte(body_t *body);
    void display(header_t *header, body_t *body, char *name);
    bool correct_type(body_t *body, int nbr);
    bool check_label(char *str);
    bool is_label(char *str);
    void label_pos(body_t *head, char **arr);

    int live(body_t *body);
    int ld_op(body_t *body);
    int st_op(body_t *body);
    int add(body_t *body);
    int sub(body_t *body);
    int and_op(body_t *body);
    int or_op(body_t *body);
    int xor_op(body_t *body);
    int zjmp(body_t *body);
    int ldi(body_t *body);
    int sti(body_t *body);
    int fork_op(body_t *body);
    int lld(body_t *body);
    int lldi(body_t *body);
    int lfork(body_t *body);
    int aff(body_t *body);

    //algorithm
    void display_help(void);
    void create_map(game_t *vm);
    void check_fork(game_t *vm);
    char *int_to_str(int num);
    void init_champlist(char **argv, game_t *vm);
    champion_t *go_first_elem(champion_t *champlist);
    champion_t *go_last_elem(champion_t *champlist);
    champion_t *delete_node(champion_t *champlist);
    champion_t *init_champion(void);
    game_t *init_vm(char **argv);
    int check_cycle(game_t *vm, int *cycle);
    ssize_t count_bytes(char *path);
    int my_list_len(champion_t *champlist);
    void sort_champlist(champion_t **head_list);
    int byte_to_int(char *str, int pos, int bytes);
    int *get_coding_type(game_t *vm);
    void dump_memory(game_t *vm);
    int *get_sizes(int *coding_type);
    int *get_params(game_t *vm, int *coding_type, int *reg, int instruction);
    bool correct_operators_and(int *coding_byte);
    int *get_sizes_st(int *coding_type);

    int live_cmd(game_t *vm);
    int ld_cmd(game_t *vm);
    int st_cmd(game_t *vm);
    int add_cmd(game_t *vm);
    int sub_cmd(game_t *vm);
    int and_cmd(game_t *vm);
    int or_cmd(game_t *vm);
    int xor_cmd(game_t *vm);
    int zjmp_cmd(game_t *vm);
    int ldi_cmd(game_t *vm);
    int sti_cmd(game_t *vm);
    int fork_cmd(game_t *vm);
    int lld_cmd(game_t *vm);
    int lldi_cmd(game_t *vm);
    int lfork_cmd(game_t *vm);
    int aff_cmd(game_t *vm);
#endif

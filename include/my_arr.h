/*
** EPITECH PROJECT, 2022
** my_arr.h
** File description:
** handles things dealing with array
*/

#ifndef MY_ARR_H_
    #define MY_ARR_H_

    #include <stdlib.h>
    #include <stddef.h>
    #include <stdbool.h>

    void free_arr(char **arr);
    char **my_arr_ini(int x, int y);
    int my_arrlen(char **arr);
    char **my_split(char const *str, char separator);
    char **my_new_split(char *str, char *separator);
    int **my_intarr_ini(int x, int y);
    void free_intarr(int **arr);
    char **my_arrcpy(char **arr);
    char **my_split_arr(char **arr, int pos);

#endif

/*
** EPITECH PROJECT, 2022
** my_num
** File description:
** handles functions dealing with nums
*/

#ifndef MY_NUM_H_
    #define MY_NUM_H_

    #include <stdbool.h>

    #define B_2 "01"
    #define B_8 "01234567"
    #define B_10 "0123456789"
    #define B_16 "0123456789ABCDEF"
    #define B_64 "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" \
    "abcdefghijklmnopqrstuvwxyz+/"

    unsigned long int my_compute_power_long(unsigned long int nb, int p);
    int my_compute_power_rec(int nb, int p);
    int my_compute_square_root(int nb);
    int my_find_prime_sup(int nb);
    int my_getnbr(char const *str);
    int my_intlen(int nb);
    int my_is_prime(int nb);
    int my_longintlen(long int nb);
    bool my_isneg(int n);
    int my_put_double(double nb, int precision);
    int my_put_nbr(int x);
    void my_sort_int_array(int *array, int size);
    int my_put_uns_int(unsigned int nb);
    char *dec_to_base(int base, unsigned long int nb, int precision);

#endif

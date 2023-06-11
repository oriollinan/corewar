/*
** EPITECH PROJECT, 2023
** dec_to_base
** File description:
** goes from dec base to other bases
*/

#include "my_num.h"
#include "my_string.h"

char *base_to_str(int nb, int base)
{
    char *str = my_malloc_ini(2);
    str[1] = '\0';

    switch (base) {
        case 2:
            str[0] = B_2[nb];
        case 8:
            str[0] = B_8[nb];
        case 10:
            str[0] = B_10[nb];
        case 16:
            str[0] = B_16[nb];
        case 64:
            str[0] = B_64[nb];
    }
    return (str);
}

char *str_precision(int precision, int p)
{
    char *str = NULL;
    int i = 0;

    if (p > precision)
        return (my_malloc_ini(p + 1));
    str = my_malloc_ini(precision);
    while (precision > p + 1) {
        str[i] = '0';
        i++;
        precision--;
    }
    return (str);
}

char *dec_to_base(int base, unsigned long int nb, int precision)
{
    int p = 0;
    int n = 0;
    char *str = NULL;
    char *tmp = NULL;

    while (my_compute_power_rec(base, p + 1) <= nb)
        p++;
    str = str_precision(precision, p);
    while (p >= 0) {
        n = nb / my_compute_power_rec(base, p);
        nb %= (int) my_compute_power_rec(base, p);
        tmp = base_to_str(n, base);
        str = my_strcat(str, tmp);
        free(tmp);
        p--;
    }
    return (str);
}

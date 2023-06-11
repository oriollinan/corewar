/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** getting numbers from a string
*/

int negative(char const *str, int x, int neg)
{
    int n_counter = 0;

    if (neg == 1 || neg == -1) {
        return (neg);
    }
    while (x - 1 >= 0 && (str[x - 1] == '-' || str[x - 1] == '+')) {
        if (str[x - 1] == '-') {
            n_counter++;
        }
        x--;
    }
    if (n_counter % 2 == 0) {
        neg = 1;
    } else {
        neg = -1;
    }
    return (neg);
}

int my_getnbr(char const *str)
{
    int x = 0;
    int res = 0;
    int neg = 0;

    while (str[x] != '\0') {
        if ('0' <= str[x] && str[x] <= '9')
            neg = negative(str, x, neg);
        while ('0' <= str[x] && str[x] <= '9') {
            res = ((res * 10) + (str[x] - '0'));
            x++;
        }
        if (str[x] < '0' || '9' < str[x])
            x++;
    }
    if (neg == 0)
        neg = 1;
    res = neg * res;
    return (res);
}

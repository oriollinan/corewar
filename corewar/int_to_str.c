/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** int_to_str.c
*/

#include <stdlib.h>

char *int_to_str(int num)
{
    int i = 0, j = 0, tempNum = num, length = 0; char* str;
    if (num == 0) {
        length = 1;
    } else {
        while (tempNum != 0) {
            length++; tempNum /= 10;
        }
    } str = (char*)malloc((length + 1) * sizeof(char));
    if (num == 0) {
        str[i++] = '0';
    } else {
        while (num != 0) {
            int digit = num % 10;
            str[i++] = digit + '0'; num /= 10;
        }
    } str[i] = '\0';
    for (j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1]; str[i - j - 1] = temp;
    } return str;
}

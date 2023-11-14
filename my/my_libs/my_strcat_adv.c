/*
** EPITECH PROJECT, 2023
** myls
** File description:
** my_strcat_adv.c
** Author: nathan.jeannot@epitech.eu
*/

#include "../my.h"

char *my_strcat_adv(char *start, char *end)
{
    int start_length = my_strlen(start);
    int end_length = my_strlen(end);
    char *str = malloc(sizeof(char) * (start_length + end_length + 1));
    int x = 0;

    for (int i = 0; i < start_length; i++) {
        str[x] = start[i];
        x++;
    }
    for (int i = 0; i < end_length; i++) {
        str[x] = end[i];
        x++;
    }
    return str;
}

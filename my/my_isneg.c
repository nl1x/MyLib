/*
** EPITECH PROJECT, 2023
** C-POOL
** File description:
** my_isneg.c
** Author: nathan.jeannot@epitech.eu
*/

#include "my.h"

int my_isneg(int n)
{
    my_putchar(n < 0 ? 'N' : 'P');
    return 0;
}

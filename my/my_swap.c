/*
** EPITECH PROJECT, 2023
** C-POOL
** File description:
** my_swap.c
** Author: nathan.jeannot@epitech.eu
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}

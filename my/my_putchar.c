/*
** EPITECH PROJECT, 2023
** MyLib
** File description:
** my_putchar.c
** Author: nathan.jeannot@epitech.eu
*/

#include <unistd.h>

int my_putchar(char c)
{
    return write(1, &c, sizeof(char));
}

/*
** EPITECH PROJECT, 2023
** myprintf
** File description:
** handle_flag_minus_d.c
*/

#include "../../../my.h"
#include "../../my_parser.h"

static void replace(char *str, char c)
{
    int i = 0;

    while (str[i] != '\0') {
        str[i] = c;
        i++;
    }
}

int handle_flag_minus_d(parser_t *parser, flag_arguments_t *flag_args)
{
    int size = 0;

    if (contains(parser->flags, '-')) {
        replace(flag_args->width, ' ');
        size += my_putstr(flag_args->precision);
        size += handle_length_mod(parser, flag_args->arg_int);
        size += my_putstr(flag_args->width);
    } else {
        size += my_putstr(flag_args->width) + my_putstr(flag_args->precision);
        size += handle_length_mod(parser, flag_args->arg_int);
    }
    return size;
}

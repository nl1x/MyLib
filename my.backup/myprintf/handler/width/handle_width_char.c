/*
** EPITECH PROJECT, 2023
** myprintf
** File description:
** handle_width_char.c
*/

#include <stdlib.h>
#include "../../../my.h"
#include "../../my_parser.h"

static char *get_str(char c, int size)
{
    char *str = malloc(sizeof(char) * (size + 1));
    int i = 0;

    while (i < size) {
        str[i] = c;
        i++;
    }
    str[i] = '\0';
    return str;
}

static int get_nb_char(parser_t *parser, int arg_length)
{
    if (parser->precision)
        return parser->width - parser->precision;
    else
        return parser->width - arg_length;
}

char *handle_width_c(parser_t *parser, int arg_length)
{
    int nb_char = parser->width - arg_length;

    nb_char = nb_char < 0 ? 0 : nb_char;
    return get_str(' ', nb_char);
}

/*
** EPITECH PROJECT, 2023
** myls
** File description:
** my_lnk_remove.c
** Author: nathan.jeannot@epitech.eu
*/

#include "../my.h"

static
void my_lnk_resetprev(lnklst_t **list)
{
    if (*list != NULL)
        (*list)->prev = NULL;
}

lnklst_t *my_lnk_remove(lnklst_t **list, void *data)
{
    lnklst_t *to_remove = my_lnk_get_by_data(*list, data);

    if (to_remove == NULL)
        return 0;
    else if (to_remove == *list) {
        *list = (*list)->next;
        my_lnk_resetprev(list);
    } else {
        to_remove->prev->next = to_remove->next;
        to_remove->next->prev = to_remove->prev;
    }
    return *list;
}

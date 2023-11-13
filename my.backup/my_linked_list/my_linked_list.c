/*
** EPITECH PROJECT, 2023
** myls
** File description:
** my_linked_list.c
** Author: nathan.jeannot@epitech.eu
*/

#include <stdlib.h>
#include "../my.h"

static lnklst_t *lnklst_get_end(lnklst_t *list)
{
    lnklst_t *next = list->next;

    while (next != NULL) {
        list = next;
        next = list->next;
    }
    return list;
}

static lnklst_t *lnklst_get_by_data(lnklst_t *list, void *data)
{
    lnklst_t *next = list;

    while (next != NULL && next->data != data)
        next = next->next;
    return next;
}

void my_lnk_add(lnklst_t *list, void *data)
{
    lnklst_t *end = lnklst_get_end(list);

    end->next = malloc(sizeof(lnklst_t));
    end->next->data = data;
    end->next->prev = end;
    end->next->next = NULL;
}

int my_lnk_remove_data(lnklst_t **list, void *data)
{
    lnklst_t *to_remove = lnklst_get_by_data(*list, data);

    if (to_remove == NULL)
        return 0;
    else if (to_remove == *list)
        *list = (*list)->next;
    else {
        to_remove->prev->next = to_remove->next;
        to_remove->next->prev = to_remove->prev;
    }
    return 1;
}

lnklst_t *my_lnk_new(void *data)
{
    lnklst_t *list = malloc(sizeof(lnklst_t));

    list->data = data;
    list->next = NULL;
    list->prev = NULL;
    return list;
}

int lnk_has_next(lnklst_t *list)
{
    return list->next != NULL;
}

lnklst_t *lnk_next(lnklst_t *list)
{
    return list->next;
}

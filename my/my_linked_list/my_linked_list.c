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
    lnklst_t *prev = list;

    while (next != NULL) {
        prev = next;
        next = prev->next;
    }
    return prev;
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

lnklst_t *my_lnk_remove(lnklst_t **list, void *data)
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
    return *list;
}

lnklst_t *my_lnk_new(void *data)
{
    lnklst_t *list = malloc(sizeof(lnklst_t));

    list->data = data;
    list->next = NULL;
    list->prev = NULL;
    return list;
}

void my_lnk_swap(lnklst_t *list1, lnklst_t *list2)
{
    void *data1 = list1->data;

    list1->data = list2->data;
    list2->data = data1;
}

void my_lnk_sort(lnklst_t *list, int (*condition)(void *data, void *key))
{
    lnklst_t *next = list->next;
    lnklst_t *nxt_cpy;
    void *key;

    while (next != NULL) {
        key = next->data;
        nxt_cpy = next;
        while (nxt_cpy != NULL && condition(nxt_cpy->data, key))
            nxt_cpy = nxt_cpy->prev;
        my_lnk_swap(nxt_cpy, next);
        next = next->next;
    }
}

/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_sort_tab
*/

#include "include/my.h"

static void process(qsort_s *qsort, int *array, char **name, int last)
{
    while (qsort->i < qsort->j) {
        for (; (array[qsort->i] <= array[qsort->pivot] && qsort->i < last);
        ++qsort->i);
        for (;  array[qsort->j] > array[qsort->pivot]; --qsort->j);
        if (qsort->i < qsort->j) {
            qsort->tmp = array[qsort->i];
            array[qsort->i] = array[qsort->j];
            array[qsort->j] = qsort->tmp;
            qsort->tmp2 = name[qsort->i];
            name[qsort->i] = name[qsort->j];
            name[qsort->j] = qsort->tmp2;
        }
    }
}

void my_qsort(int *array, char **name, int first, int last)
{
    qsort_s *qsort_s = malloc(sizeof(qsort_s) * 4);

    if (first < last) {
        qsort_s->pivot = first;
        qsort_s->i = first;
        qsort_s->j = last;
        process(qsort_s, array, name, last);
        qsort_s->tmp = array[qsort_s->pivot];
        qsort_s->tmp2 = name[qsort_s->pivot];
        array[qsort_s->pivot] = array[qsort_s->j];
        array[qsort_s->j] = qsort_s->tmp;
        name[qsort_s->pivot] = name[qsort_s->j];
        name[qsort_s->j] = qsort_s->tmp2;
        my_qsort(array, name, first, qsort_s->j - 1);
        my_qsort(array, name, qsort_s->j + 1, last);
    }
    free (qsort_s);
}
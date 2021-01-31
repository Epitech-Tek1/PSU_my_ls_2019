/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** display_2
*/

#include "main/main.h"

void display_t(main_s *main_s)
{
    struct stat fileStat;
    DIR *rep = opendir(main_s->filepath);
    int *arr = malloc(sizeof(int) * 100);
    char **name = malloc(sizeof(char *) * 100);
    int i = 0;

    for (struct dirent *dir; dir = readdir(rep);) {
        if (dir->d_name[0] != '.') {
            stat(dir->d_name, &fileStat);
            arr[i] = fileStat.st_mtime;
            name[i] = my_strdup(dir->d_name);
            ++i;
        }
    }
    arr[i] = '\0';
    name[i] = '\0';
    my_qsort(arr, name, 0, i - 1);
    for (i -= 1; i != -1; i--)
        my_printf("%s  ", name[i]);
    my_putchar('\n');
}

void display_rmaj(main_s *main_s)
{
    struct dirent *dirent;
    struct stat fileStat;
    DIR *dir;
    char *tmp = main_s->filepath;

    my_printf("%s:\n", main_s->filepath);
    display_basics(main_s);
    my_putchar('\n');
    dir = opendir(main_s->filepath);
    while ((dirent = readdir(dir)) != 0) {
        main_s->filepath = my_strcat(my_strcat(tmp, "/"), dirent->d_name);
        stat(main_s->filepath, &fileStat);
        if (S_ISDIR(fileStat.st_mode) && dirent->d_name[0] != '.')
            display_rmaj(main_s);
    }
}
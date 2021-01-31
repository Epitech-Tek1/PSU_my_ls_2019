/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** display_process
*/

#include "main/main.h"
#include <pwd.h>
#include <string.h>

static void display_l(main_s *main_s)
{
    struct stat fileStat;
    DIR *rep = opendir(main_s->filepath);
    struct dirent *dir;

    my_printf("total %d\n", total_block(main_s));
    while ((dir = readdir (rep))) {
        if (dir->d_name[0] != '.') {
            stat(dir->d_name, &fileStat);
            get_authorization(fileStat);
            my_printf("%d ", fileStat.st_nlink);
            my_printf("%s ", getpwuid(fileStat.st_uid)->pw_name);
            my_printf("%s ", getgrgid(fileStat.st_gid)->gr_name);
            my_printf("%d ", fileStat.st_size);
            write(1, (ctime(&fileStat.st_mtime) + 4), \
                (my_strlen(ctime(&fileStat.st_mtime)) - 13));
            my_putchar(' ');
            my_putstrc(dir->d_name, (dir->d_type == DT_DIR) ? BLUE : GREEN, 1);
            my_printf("\n");
        }
    }
}

static void display_d(main_s *main_s)
{
    DIR *rep;

    if (main_s->ac == 2) {
        my_printf(".\n");
        return;
    }
    rep = opendir(main_s->av[2]);
    if (rep == NULL)
        rep_error(main_s, main_s->av[2]);
    my_printf("%s\n", main_s->av[2]);
}

void display_basics(main_s *main_s)
{
    struct dirent *dir;
    DIR *rep = opendir(main_s->filepath);

    while ((dir = readdir (rep)) != NULL)
        if (dir->d_name[0] != '.') {
            my_putstrc(dir->d_name, (dir->d_type == DT_DIR) ? BLUE : GREEN, 1);
            my_putstr("  ");
        }
    my_printf("\n");
    closedir(rep);
}

static void (* display_fct[])(main_s *) =
{
    display_l,
    display_d,
    display_rmaj,
    display_t
};

void display(main_s *main_s)
{
    char flag[] = "ldRtr";
    DIR *dir;

    main_s->filepath = (main_s->ac == 3) ? main_s->av[2] : ".";
    if (main_s->ac == 1 || (main_s->ac == 2 && main_s->av[1][0] != '-')) {
        main_s->filepath = (main_s->ac == 2) ? main_s->av[1] : ".";
        display_basics(main_s);
        return;
    }
    if (main_s->ac == 3) {
        dir = opendir(main_s->av[2]);
        if (dir == NULL)
            rep_error(main_s, main_s->av[2]);
    }
    for (int i = 0; flag[i]; ++i)
        if (main_s->av[1][1] == flag[i])
            display_fct[i](main_s);
}
/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** error_handling
*/

#include "main/main.h"

int rep_error(main_s *main_s, char *flag)
{
    char *error_beg = my_strdup("ls: cannot access '");
    char *error_end = my_strdup("': No such file or directory");

    error_beg = my_strcat(error_beg, flag);
    error_end = my_strcat(error_beg, error_end);
    my_printf("%s\n", error_end);
    free (main_s);
    exit(EXIT_ERROR);
}

int preg_match(main_s *main_s, char *flag)
{
    DIR *rep = opendir(flag);

    if (rep == NULL && flag[0] != '-')
        return (EXIT_ERROR);
    return ((my_strcmp("-l", flag) == 0 || my_strcmp("-d", flag) == 0
    || my_strcmp("-R", flag) == 0 || my_strcmp("-r", flag) == 0
    || my_strcmp("-t", flag) == 0) ?
    (EXIT_SUCCESS) : (EXIT_ERROR));
}

int error_handling(main_s *main_s)
{
    if (main_s->ac == 1)
        return (EXIT_SUCCESS);
    if (84 == preg_match(main_s, main_s->av[1]))
        rep_error(main_s, main_s->av[1]);
    return (EXIT_SUCCESS);
}
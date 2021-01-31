/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** main
*/

#include "main/main.h"

void process_error(main_s *main_s)
{
    free(main_s);
    exit(EXIT_ERROR);
}

int main(int ac, char **av)
{
    main_s *main_s = malloc(sizeof(main_s) + sizeof(av) + sizeof(char) * 10000);

    if (!main_s)
        process_error(main_s);
    if (84 == initialisation(main_s, ac, av) OR 84 == error_handling(main_s))
        process_error(main_s);
    process(main_s);
    free(main_s);
    return (EXIT_SUCCESS);
}
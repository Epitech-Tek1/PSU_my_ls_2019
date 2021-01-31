/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** basics
*/

#include "main/main.h"

int initialisation(main_s *main_s, int ac, char **av)
{
    main_s->ac = ac;
    main_s->av = wa_to_wa(av);
    return (EXIT_SUCCESS);
}
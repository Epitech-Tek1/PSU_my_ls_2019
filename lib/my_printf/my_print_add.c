/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_print_add
*/

#include "my_printf.h"

int my_print_add(va_list str_print, char *str, int i)
{
    int nbr = va_arg(str_print, int);

    if (str[i + 1] == 'd' || str[i + 1] == 'i') {
        (nbr < 0) ? my_put_nbr(nbr) : (my_putchar('+'), my_put_nbr(nbr));
        return (i + 1);
    }
    check_flag(str, i + 1, str_print);
    return (i);
}
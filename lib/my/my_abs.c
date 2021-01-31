/*
** EPITECH PROJECT, 2020
** my
** File description:
** my_abs
*/

#include "include/my.h"

int my_abs(int nbr)
{
    return (nbr < 0) ? (nbr *= (-1)) : (nbr);
}
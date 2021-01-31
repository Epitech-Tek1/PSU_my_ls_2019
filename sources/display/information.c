/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** information
*/

#include "main/main.h"

void get_authorization(struct stat fileStat)
{
    my_printf("%s", (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    my_printf("%s", (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    my_printf("%s", (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    my_printf("%s", (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    my_printf("%s", (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    my_printf("%s", (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    my_printf("%s", (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    my_printf("%s", (fileStat.st_mode & S_IROTH) ? "r" : "-");
    my_printf("%s", (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    my_printf("%s ", (fileStat.st_mode & S_IXOTH) ? "x" : "-");
}
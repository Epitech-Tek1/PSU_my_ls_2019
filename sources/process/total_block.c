/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** total_block
*/

#include "main/main.h"

int total_block(main_s *main_s)
{
    struct stat fileStat;
    struct dirent *dirent;
    int block = 0;
    DIR *dir = opendir(".");
    char *name;

    while ((dirent = readdir(dir))) {
        name = my_strcat(my_strcat(".", "/"), dirent->d_name);
        if ((lstat(name, &fileStat)) == 0)
            block += (dirent->d_name[0] != '.') ? fileStat.st_blocks : 0;
    }
    closedir(dir);
    return (block / 2);
}
/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** cmd_cd.c
*/

#include "my.h"

void cmd_cd(char *arg)
{
    if (arg != NULL) {
        int result = chdir(arg);
        if (result != 0)
            my_printf("cd: aucun fichier ou dossier de ce type: %s\n", \
                arg);
    }
}

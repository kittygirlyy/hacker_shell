/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** exec_cmd.c
*/

#include "my.h"

int exec_cmd(char *arg)
{
    char save_arg[my_strlen(arg)];
    my_strcpy(save_arg, arg);
    save_arg[my_strlen(arg)] = '\0';
    char *next_arg = NULL;
    strtok_r(save_arg, " ", &next_arg);
    if (my_strcmp(save_arg, "clear") == 0) {
        cmd_clear();
        return 0;
    }
    if (my_strcmp(save_arg, "cd") == 0) {
        cmd_cd(next_arg);
        return 0;
    }
    if (my_strcmp(save_arg, "exit") == 0) {
        exit(0);
        return 0;
    }
    if (env_handler(save_arg, next_arg) == 0)
        return 0;
    return 1;
}

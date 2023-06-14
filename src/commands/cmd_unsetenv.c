/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** cmd_unsetenv.c
*/

#include "my.h"

static void unsetenv_main(char **env_list, char *env, int nb_env);

int fc_unsetenv(char **env_list, char *env, int nb_env)
{
    if (my_strcmp(env, "") == 0) {
        my_printf("Usage : <name>\n");
        return 0;
    }
    unsetenv_main(env_list, env, nb_env);
    return 0;
}

static void unsetenv_main(char **env_list, char *env, int nb_env)
{
    int index = -1;
    for (int i = 0; env_list[i] != NULL; i++) {
        char *var_name = strtok(env_list[i], "=");
        if (var_name != NULL && my_strcmp(var_name, env) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        free(env_list[index]);
        for (int i = index; env_list[i] != NULL; i++)
            env_list[i] = env_list[i + 1];
        nb_env--;
    }
}

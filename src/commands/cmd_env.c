/*
** PROJECT, 2023
** minishell1
** File description:
** cmd_setenv.c
*/

#include "my.h"

static void env_parser(int *nb_env, char **env_list, char *next_arg);
static void make_env(char *name, char *value);

int env_handler(char *arg, char *next_arg)
{
    static char *env_list[MAX_ENVS];
    static int nb_env = 0;
    if (my_strcmp(arg, "setenv") == 0) {
        if (my_strcmp(next_arg, "") == 0) {
            my_printf("Usage : <name> <value>\n");
            return 0;
        }
        env_parser(&nb_env, env_list, next_arg);
        return 0;
    }
    if (my_strcmp(arg, "env") == 0) {
        for (int i = 0; env_list[i] != NULL; i++)
            my_printf("%s\n", env_list[i]);
        return 0;
    }
    if (my_strcmp(arg, "unsetenv") == 0)
        return fc_unsetenv(env_list, next_arg, nb_env);
    return 1;
}

static void env_parser(int *nb_env, char **env_list, char *next_arg)
{
    char *name = strtok(next_arg, " ");
    char *value = strtok(NULL, " ");
    if (name != NULL && value != NULL) {
        make_env(name, value);
        if (*nb_env < MAX_ENVS - 1) {
            env_list[*nb_env] = my_strdup(next_arg);
            (*nb_env)++;
            env_list[*nb_env] = NULL;
        }
    }
}

static void make_env(char *name, char *value)
{
    char save_value[my_strlen(value)];
    my_strcpy(save_value, value);
    save_value[my_strlen(value)] = '\0';
    my_strcat(name, "=");
    my_strcat(name, save_value);
}

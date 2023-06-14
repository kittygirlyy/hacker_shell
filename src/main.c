/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** main.c
*/

#include "my.h"

static void main_loop(char *buffer, size_t buffsize);
static void command_handler(char *arg);

int main(void)
{
    char *buffer;
    size_t buffsize = 32;
    buffer = malloc(buffsize * sizeof(char *));
    main_loop(buffer, buffsize);
    return 0;
}

static void main_loop(char *buffer, size_t buffsize)
{
    while (1) {
        char cwd[1048];
        getcwd(cwd, sizeof(cwd));
        my_printf("\n►►%s\n$>", cwd);
        getline(&buffer, &buffsize, stdin);
        int nb_char = count_arg(buffer);
        char *arg = check_arg(buffer, nb_char);
        command_handler(arg);
    }
}

static void command_handler(char *arg)
{
    if (my_strcmp(arg, "") != 0) {
        if (exec_cmd(arg) != 0)
            system_cmd(arg);
    }
}

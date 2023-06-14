/*
** PROJECT, 2023
** minishell1
** File description:
** cmd_clear.c
*/

#include "my.h"

void cmd_clear(void)
{
    pid_t pid = fork();
    if (pid == 0) {
        char *argv[] = {"clear", NULL};
        char *envp[] = {"TERM=xterm", NULL};
        execve("/usr/bin/clear", argv, envp);
        perror("execve");
        exit(1);
    } else
        wait(NULL);
}

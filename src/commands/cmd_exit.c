/*
** PROJECT, 2023
** shell_in_C
** File description:
** cmd_exit.c
*/

#include "my.h"

void cmd_exit(void)
{
    pid_t pid = getpid();
    printf("Successful killed %d\n", pid);
    kill(pid, SIGTERM);
}

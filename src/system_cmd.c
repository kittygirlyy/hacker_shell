/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** system_cmd.c
*/

#include "my.h"

void system_cmd(char *arg)
{
    pid_t pid = fork();
    if (pid == 0) {
        system_functions(arg);
        exit(1);
    } else
        wait(NULL);
}

void system_functions(char *arg)
{
    char *command = strtok(arg, " ");
    DIR *dp = opendir("/usr/bin");
    if (dp == NULL) {
        perror("opendir");
        return;
    }
    system_functions_loop(dp, command);
    closedir(dp);
}

void system_functions_loop(DIR *dp, char *command)
{
    struct dirent *entry;
    while ((entry = readdir(dp))) {
        if (my_strcmp(entry->d_name, command) == 0) continue;
        char *full_path = malloc(my_strlen("/usr/bin/") + \
            my_strlen(command) + 1);
        my_strcpy(full_path, "/usr/bin/");
        my_strcat(full_path, command);
        int argc = 1;
        char *args[MAX_ARGS] = {full_path, NULL};
        char *token;
        while ((token = strtok(NULL, " ")))
            args[argc++] = token;
        args[argc] = NULL;
        int res = execve(full_path, args, NULL);
        if (res != -1)
            perror("execve");
        my_printf("%s: Commande introuvable.\n", command);
        free(full_path);
        break;
    }
}

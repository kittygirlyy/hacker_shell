/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** filtre_arg.c
*/

#include "my.h"

int count_arg(char *buffer)
{
    int i = 0;
    while (buffer[i] != '\n')
        i++;
    return i;
}

char *check_arg(char *buffer, int nb_char)
{
    char *arg = malloc(sizeof(char *) * nb_char);
    for (int i = 0; i < nb_char; i++) {
            arg[i] = buffer[i];
    }
    return arg;
}

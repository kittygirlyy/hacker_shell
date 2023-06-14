/*
** PROJECT, 2023
** minishell1
** File description:
** my.h
*/

#ifndef MY_
    #define MY_

    /* Library include */
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdarg.h>
    #include <dirent.h>
    #include <sys/wait.h>

    /* Macros */
    #define MAX_ARGS 20
    #define MAX_ENVS 496

    /* Source functions */
    int count_arg(char *buffer);
    char *check_arg(char *buffer, int nb_char);
    void system_cmd(char *arg);
    void system_functions(char *arg);
    void system_functions_loop(DIR *dp, char *command);
    int exec_cmd(char *arg);

    /* commands */
    void cmd_cd(char *arg);
    void cmd_clear(void);
    int env_handler(char *arg, char *next_arg);
    int fc_unsetenv(char **env_list, char *env, int nb_env);
    void cmd_exit(void);

    /* Library functions */
    int my_printf(const char* format, ...);
    void my_put_float(double nb);
    int my_putlong_float(long nb1, char *basic);
    int my_put_nbr(int nb1);
    void my_putchar(char c);
    int my_putstr(char const *arr);
    int my_strlen(char const *arr);
    int my_printf(const char* format, ...);
    void my_put_hex_upper(int nb);
    void my_put_hex_lower(int nb);
    int my_put_octal(int nb);
    void my_put_bin(unsigned int n);
    char *binary(unsigned n, char buffer[]);
    void my_put_u(unsigned int nb);
    int conditions01(const char* format, int i, va_list list);
    int conditions02(const char* format, int i, va_list list);
    int my_second_float(long d2_2, double d2, int i);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strdup(char *str);
    char *my_strcpy(char *dest, char *src);
    char *my_strcat(char *dest, char const *src);

#endif /* !MY_ */

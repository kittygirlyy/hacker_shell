##
## PROJECT, 2023
## minishell1
## File description:
## Makefile
##

CFLAGS = -Wall -Wextra -Iinclude -L. -l:./library.a

SRC	= 	src/main.c \
		src/check_arg.c \
		src/system_cmd.c \
		src/exec_cmd.c \

COMMANDS =	src/commands/cmd_cd.c \
			src/commands/cmd_clear.c \
			src/commands/cmd_env.c \
			src/commands/cmd_unsetenv.c \
			src/commands/cmd_exit.c \

LDNAME = library/

OBJ = $(SRC:.c=.o) $(COMMANDS:.c=.o)

NAME = mysh

$(NAME): $(OBJ)
	@make -C $(LDNAME)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\033[32m[OK]\033[0m": $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f coding-style-reports.log
	@rm -f *.gcno *.gcda *.gcov vgcore.*
	@echo -e "\033[31m[RM]\033[0m": $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LDNAME) $@
	@echo -e "\033[31m[RM]\033[0m": $(NAME)

re: fclean all

.PHONY: all clean fclean re

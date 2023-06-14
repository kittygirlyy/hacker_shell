##
## PROJECT, 2023
## 1337_snake
## File description:
## makefile
##

NAME	=	1337_snake

SRC	=	main.py

$(NAME):
	cp $(SRC) $(NAME)
	chmod 755 $(NAME)

all:	$(NAME)

fclean:
	rm -f $(NAME)

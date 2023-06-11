##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile create library for dante
##

SRC	=	$(wildcard *.c)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I./../include -g3

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

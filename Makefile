##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile create binary for generator and solver
##

all:
			make -C lib/
			make -C asm/
			make -C corewar/

clean:
			make clean -C lib/
			make clean -C asm/
			make clean -C corewar/

fclean:		clean
			make fclean -C lib/
			make fclean -C asm/
			make fclean -C corewar/

re:			fclean all

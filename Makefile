##
## EPITECH PROJECT, 2020
## Makefile
## File description:
##  makefile
##

SRC			=		src/main.c 				\
					src/loop.c				\
					src/loop_2.c			\
					src/map.c				\
					src/print.c				\
					src/print_2.c			\
					src/ai.c
		
OBJ 		= 		$(SRC:.c=.o)

NAME 		=		matchstick

CFLAGS 		= 		 -I./include 

LIB 		=		-L./lib/my -lmy

CC			= 		gcc

all: $(NAME)

$(NAME): 		$(OBJ)
		make -C lib/my/
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)

clean:
		$(RM) -f $(OBJ)
		$(RM)  -f lib/my/*.o

fclean:		clean
		$(RM) -f $(NAME) *.gc*
		$(RM) -f $(NAME)

re: 	fclean all

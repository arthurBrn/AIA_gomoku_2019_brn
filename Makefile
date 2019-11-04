##
## EPITECH PROJECT, 2019
## Make file lib
## File description:
## create exe

SRC	=	main.c\
		gomoku.c\
		error.c\
		start.c\

CC	=	gcc

CFLAGS	=	-W -Wall -pipe -I./include/

OBJ	=	$(SRC:%.c=%.o)

NAME	=	gomoku

all:		$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C ./lib
		$(CC) -o $(NAME) $(OBJ) -L./lib -lmy

clean:
		rm -f $(OBJ)
		$(MAKE) -C ./lib clean

fclean: 	clean
		$(RM) $(NAME)
		$(MAKE) -C ./lib fclean

re:		all

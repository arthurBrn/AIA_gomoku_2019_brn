##
## EPITECH PROJECT, 2019
## Make file tests
## File description:
## create exe unit_test
##

SRC	=	test_error.c\
		../error.c
#		../store_board.c
#test_node.c

CFLAGS	=	-I../include/

LDFLAGS	=	-Wall -Wextra --coverage -lcriterion -lgcov

OBJ	=	$(SRC:%.c=%.o)

CC	=	gcc

NAME	=	unit_test

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) #-L../lib/ -lmy

clean:
		rm -f $(OBJ)

fclean: 	clean
		$(RM)  $(NAME)
		$(RM) $(OBJ)
re: 		fclean all

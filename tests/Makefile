##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile test
##

NAME	=	unit_test

SRC_TEST	=	tests.c

SRC		=	../src/board.c						\
			./src/run_start.c					\
			./src/run_board.c					\
			./src/run_end.c						\
			./src/my_str_to_word_array.c		\
			./src/utils.c						\
			./src/board.c						\
			./src/read.c						\			
OBJ 	=	$(SRCS:.c=.o)

INCLUDE	=	-I../include

CFLAGS	=	$(INCLUDE) --coverage

LDFLAGS	=	-lcriterion -lgcov

CC	=	gcc

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(SRC_TEST) $(LDFLAGS)

clean:
		$(RM) *.o

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(wildcard *.gc*)

re: fclean all

.PHONY:	all clean fclean re

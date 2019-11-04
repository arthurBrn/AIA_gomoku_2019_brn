##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile test
##

NAME	=	unit_test

SRC_TEST	=	tests.c

SRC	=	../src/board.c

INCLUDE	=	-I../include

CFLAGS	=	$(INCLUDE) --coverage

LDFLAGS	=	-lcriterion -lgcov

CC	=	gcc

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(SRC_TEST) $(LDFLAGS)

clean:
		$(RM) *.o

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(wildcard *.gc*)

re: fclean all

.PHONY:	all clean fclean re

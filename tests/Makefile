##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile test
##

NAME	=	unit_test

SRC_TEST	=	tests.c\
			test_error_check_players.c\
			test_error_nbr_coma.c\
			test_error_only_digit_str.c\
			test_error_coordinate.c\
			test_node_creation.c\
			test_node_length.c\
			test_node_matching_nodes.c\
			test_node_global.c\

SRC		=	../src/run_start.c					\
			../src/cmd.c\
			../src/run_board.c					\
			../src/run_end.c						\
			../src/run_turn.c\
			../src/my_intlen.c\
			../src/my_str_to_word_array.c		\
			../src/utils.c						\
			../src/board.c						\
			../src/read.c						\
			../src/error.c\
			../src/store_board.c\

OBJ 	=	$(SRC:.c=.o)

INCLUDE	=	-I../include

CFLAGS	=	$(INCLUDE) --coverage

LDFLAGS	=	-lcriterion -lgcov

CC	=	gcc

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(SRC_TEST) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)
		$(RM) $(wildcard *.gc*)

re: fclean all

.PHONY:	all clean fclean re

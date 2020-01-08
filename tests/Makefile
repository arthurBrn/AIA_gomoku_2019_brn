##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile test
##

NAME	=	unit_test

SRC_TEST	=	test_run_board.c			\
				test_error_check_string.c	\
				test_error_check_players.c \
				test_error_coordinate.c \
				test_error_nbr_coma.c\
				test_error_only_digit_str.c\
				test_sort_list.c\
				

SRC		=	../src/run_start.c					\
			../src/run_begin.c					\
			../src/run_board.c					\
			../src/run_end.c					\
			../src/run_turn.c					\
			../src/run_move.c 					\
			../src/print_board.c 				\
			../src/commands.c					\
			../src/my_str_to_word_array.c				\
			../src/utils.c						\
			../src/gomoku.c						\
			../src/error.c						\
			../src/board_utils.c				\

OBJ 	=	$(SRC:.c=.o)

INCLUDE	=	-I../include

CFLAGS	=	$(INCLUDE) --coverage -O0

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
		$(RM) ./../src/*.gcno
		$(RM) ./../src/*.gcda

re: fclean all

.PHONY:	all clean fclean re

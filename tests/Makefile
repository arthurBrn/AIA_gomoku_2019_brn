##
## EPITECH PROJECT, 2019
## makefile
## File description:
## Makefile test
##

NAME	=	unit_test

SRC_TEST	=	test_error_check_players.c	\
			test_error_nbr_coma.c		\
			test_error_only_digit_str.c	\
			test_error_coordinate.c		\
			test_node_global.c		\
			test_utils.c			\
			test_read.c			\
			test_run_begin.c		\
			test_run_board.c		\
			test_run_end.c			\
			test_run_start.c		\
			test_run_turn.c			\
			test_check_turn_errors.c	\
			test_tree.c			\
			test_store_board.c		\
			test_check_aligned.c		\
			test_store_aligned.c		\
			test_make_move.c		\
			test_check_vertical.c		\

SRC		=	../src/run_start.c					\
			../src/run_begin.c					\
			../src/commands.c					\
			../src/run_board.c					\
			../src/run_end.c					\
			../src/run_turn.c					\
			../src/my_intlen.c					\
			../src/my_str_to_word_array.c				\
			../src/utils.c						\
			../src/gomoku.c						\
			../src/error.c						\
			../src/store_board.c					\
			../src/check_turn_errors.c				\
			../src/empty_list.c					\
			../src/print_list.c					\
			../src/check_aligned.c					\
			../src/tree.c						\
			../src/print_the_board.c				\
			../src/store_aligned.c					\
			../src/make_move.c					\
			../src/check_vertical.c					\
			../src/check_diag_left_to_right.c			\
			../src/check_diag_right_to_left.c		\
			../src/check_consecutives_diag_rtol.c	\
			../src/check_consecutives_diag_ltor.c	\

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

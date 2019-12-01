##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## ..
##

NAME	=	pbrain-gomoku-ai

CC	=	gcc

SRCS	=	./src/commands.c					\
		./src/run_start.c					\
		./src/run_board.c					\
		./src/run_end.c						\
		./src/my_str_to_word_array.c				\
		./src/utils.c						\
		./src/gomoku.c		   				\
		./src/main.c						\
		./src/run_turn.c					\
		./src/my_intlen.c					\
		./src/run_begin.c					\
		./src/store_board.c					\
		./src/error.c						\
		./src/check_turn_errors.c				\
		./src/print_list.c					\
		./src/check_aligned.c					\
		./src/check_vertical.c					\
		./src/check_diag_left_to_right.c			\
		./src/store_aligned.c							\
		./src/print_the_board.c 						\
		./src/check_consecutives_diag_ltor.c			\
		./src/check_diag_right_to_left.c				\
		./src/check_consecutives_diag_rtol.c			\
		./src/make_move.c 								\

OBJS	=	$(SRCS:.c=.o)

TEST_DIR=	tests/

CFLAGS =	-I ./include/

CFLAGS +=	-W -Wall -Wextra -Wshadow

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(TEST_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(TEST_DIR) fclean

re: fclean all

debug: $(CFLAGS) += -g

debug: $(NAME)

tests_run:
	$(MAKE) -C $(TEST_DIR)
	./$(TEST_DIR)unit_test

coverage:
	gcovr --exclude tests --branch

.PHONY: all clean fclean re tests_run

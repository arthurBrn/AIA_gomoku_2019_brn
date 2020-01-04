##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## ..
##

NAME	=	pbrain-gomoku-ai

CC	=	gcc -g

SRCS	=	./src/commands.c					\
		./src/my_str_to_word_array.c				\
		./src/utils.c						\
		./src/gomoku.c		   				\
		./src/run_start.c	   				\
		./src/run_begin.c	   				\
		./src/run_end.c		   				\
		./src/run_board.c					\
		./src/error.c						\
		./src/main.c						\
		./src/board_utils.c					\
		./src/print_board.c                 \
		./src/run_turn.c					\

OBJS	=	$(SRCS:.c=.o)

TEST_DIR	=	tests/

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

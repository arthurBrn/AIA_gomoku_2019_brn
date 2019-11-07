##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## ..
##

NAME	=	pbrain-gomoku-ai

CC	=	gcc -g

RM	=	rm -f

SRCS	=	./src/cmd.c						\
		./src/run_start.c					\
		./src/run_board.c					\
		./src/run_end.c						\
		./src/my_str_to_word_array.c				\
		./src/utils.c						\
		./src/board.c						\
		./src/read.c						\
		./src/main.c						\
		./src/run_turn.c					\
		./src/my_intlen.c

OBJS	=	$(SRCS:.c=.o)

TEST_DIR=	tests/

CFLAGS =	-I ./include/

CFLAGS +=	-W -Wall -Wextra

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

tests_run: 
	$(MAKE) -C $(TEST_DIR)

.PHONY: all clean fclean re tests_run

##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## ..
##

NAME	=	gomoku

CC	=	gcc

RM	=	rm -f

SRCS	=	./src/board.c 

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

tests_run: $(OBJS)
	$(MAKE) -C $(TEST_DIR)

.PHONY: all clean fclean re tests_run

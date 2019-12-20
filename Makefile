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
		./src/main.c						

OBJS	=	$(SRCS:.c=.o)


CFLAGS =	-I ./include/

CFLAGS +=	-W -Wall -Wextra -Wshadow

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: $(CFLAGS) += -g

debug: $(NAME)


.PHONY: all clean fclean re tests_run

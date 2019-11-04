##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## ..
##

NAME	=	pbrain-gomoku-ai

CC	=	gcc -g

RM	=	rm -f

SRCS	=	./src/cmd.c			\
		./src/run_start.c		\
		./src/run_board.c		\
		./src/run_end.c			\
		./src/main.c 

OBJS	=	$(SRCS:.c=.o)

CFLAGS =	-I ./include/
CFLAGS +=	-W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

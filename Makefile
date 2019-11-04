##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## ..
##

NAME	=	pbrain-gomoku-ai

CC	=	gcc

RM	=	rm -f

SRCS	=	./src/main.c 

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

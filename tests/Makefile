##
## EPITECH PROJECT, 2019
## Make file tests
## File description:
## create exe unit_test
##

SRC	=	test_error_check_players.c\
		test_error_nbr_coma.c\
		test_error_only_digit_str.c\
		test_error_coordinate.c\
		test_node_creation.c\
		test_node_length.c\
		test_node_matching_nodes.c\
		test_node_global.c\
		../src/error.c\
		../src/my_str_to_word_array.c\
		../src/store_board.c\

CFLAGS	=	-I../include/

LDFLAGS	=	-Wall -Wextra --coverage -lcriterion -lgcov

OBJ	=	$(SRC:%.c=%.o)

CC	=	gcc

NAME	=	unit_test

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) #-L../lib/ -lmy

clean:
		rm -f $(OBJ)

fclean: 	clean
		$(RM)  $(NAME)
		$(RM) $(OBJ)
re: 		fclean all

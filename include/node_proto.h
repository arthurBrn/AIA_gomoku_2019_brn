/*
** EPITECH PROJECT, 2019
** node_proto
** File description:
** protos
*/

#define EXIT_USAGE 84
#define ERROR_MSG "error"
#define SYNTAX_ERROR_MSG "Syntax error"

// linked_list_t create_node(char *x, char *y, char *player);
int valid_str(char *str);
int nbr_coma(char *str);
int check_players(char *str);
void invalid_string(void);
int check_string(char *str);
void store_board(char *str);
char *split_string(char *str, char *delimiter);
int check_corrdinate(char **array);

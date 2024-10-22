#ifndef PRUEBA_MINI_H
# define PRUEBA_MINI_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0
# define PIPE '|'
# define INPUT '<'
# define OUTPUT '>'
# define DELIMITER "<<"
# define APPEND ">>"
# define SPACE ' '

//COLORS
# define RED	"\001\033[1;31m\002"
# define GREEN	"\001\033[1;32m\002"
# define YELLOW	"\001\033[1;33m\002"
# define BLUE	"\001\033[1;34m\002"
# define PURPLE	"\001\033[1;95m\002"
# define CYAN	"\001\033[1;36m\002"
# define WHITE	"\001\033[1;37m\002"
# define END	"\001\033[0m\002"

typedef struct s_chars	t_chars;
typedef struct s_data	t_data;
typedef struct s_cmds	t_cmds;

struct s_chars
{
	int	pipe;
	int	input;
	int	output;
	int	append;
	int	delim;
};

struct s_cmds
{
	int	pipe;
	int	input;
	int	output;
	int	append;
	int	delim;
	char			*cmd;
	struct s_cmds	*next;
};

struct s_data
{
	t_chars	*ptr_chars;
	char	**words;
};

//QUOTES.C
void	while_end(char *line, int i);
int		search_end_quote(char *line, int i);
char	*extract_quote(char *line, int start, int final);
char	*find_quote(char *line, int i);
void	search_end_while(char *line);

//COUNT.C
int		count_end_quote(char *line, int i);
int		count_end_word(char *line, int i);
int		count_words(char *line);

//WORDS.C
char	*find_words(char *line, int i);

//SIGNAL.C
void	find_signal(void);

//CHECK_CHARS.C
int		check_chars(char **words, t_chars *chars);
int		m_ischar(char *c, t_cmds *node);

//EXECUTE.C
void	execute_cmds(char **words, int num_words);

//LIST_COMMAND.C
t_cmds	*list_cmd(t_cmds *command, char **words);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:32:18 by mignavar          #+#    #+#             */
/*   Updated: 2025/02/18 15:41:50 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "env.h"
# include <sys/ioctl.h>
# include <wait.h>

# define TRUE 1
# define FALSE 0
# define PIPE '|'
# define INPUT '<'
# define OUTPUT '>'
# define DELIMITER "<<"
# define APPEND ">>"
# define READ 0
# define WRITE 1

//COLORS
# define RED	"\001\033[1;31m\002"
# define GREEN	"\001\033[1;32m\002"
# define YELLOW	"\001\033[1;33m\002"
# define BLUE	"\001\033[1;34m\002"
# define PURPLE	"\001\033[1;95m\002"
# define CYAN	"\001\033[1;36m\002"
# define WHITE	"\001\033[1;37m\002"
# define END	"\001\033[0m\002"

typedef struct s_data	t_data;
typedef struct s_cmds	t_cmds;
typedef struct s_exec	t_exec;

extern int				g_signal_c;
struct s_cmds
{
	char			*cmd;
	int				quote;
	struct s_cmds	*next;
};

struct s_data
{
	int		pipe_fd[2];
	int		clon_stdin;
	int		clon_stdout;
	int		to_close;
	char	**words;
	int		last_exit;
	int		quote_chars;
	int		new_quote;
	int		sym_list;
	int		word_list;
	int		have_redir;
};

struct s_exec
{
	t_cmds	*now;
	t_cmds	*next;
	t_data	*data;
	t_env	*env;
};

//----------------PARSE--------------------------------//
char	**search_in_line(char *line, t_data *data, t_env *env);

//QUOTES.C
void	while_end(char *line, int i);
int		search_end_quote(char *line, int i);
char	*find_quote(char *line, int init, t_data *data);
void	search_end_while(char *line);

//COUNT.C
int		count_end_quote(char *line, int i);
int		count_end_word(char *line, int i);
int		count_words(char *line);

//WORDS.C
char	*find_words(char *line, int i, t_data *data);

//SIGNAL.C
void	find_signal(void);

//CHECK_CHARS.C
int		m_ischar(char *c);

//EXPAND_VARIABLE.C
char	*join_var_more(char *old_word, char *new_word, char *value);
char	*expand_var_quote(char *old_word, char *new_word,
			t_env *env, t_data *data);
char	*double_quote(char *old_word, char *new_word, t_env *env, t_data *data);

//CLEAN_AND_EXPAND.C
char	**clean_and_expand(char **words, t_env *env, t_data *data);

//-----------------EXECUTE------------------------------//
//EXECUTE_CMD.C
void	execute_cmd(char **command, t_env *env, pid_t pid, t_data *data);

//EXECUTE_CD.C
void	execute_cd(char **command, t_env *env);

//EXECUTE_ECHO.C
void	execute_echo(char **command);

//EXECUTE_PWD.C
void	execute_pwd(void);

//EXECUTE_ENV.C
void	execute_env(char **command, t_env *env);
void	execute_export(char **command, t_env *env);
void	execute_unset(char **command, t_env *env);

//EXECUTE_REDIRECTION.C
int		execute_redirection(char **command, t_exec *exec,
			t_env *env, t_data *data);

//EXECUTE_REST.C
void	execute_rest(char **command, t_env *env, t_data *data);
void	execute_rest_pid(char **command, t_env *env, t_data *data);

//EXECUTE.C
void	loop_cmd(t_exec *exec, t_env *env, t_data *data);
void	execute(t_cmds **cmd, t_env *env, t_data *data);

//EXECUTE_UTILS.C
char	*search_route(char *command, char **envp);
char	**set_env(t_env *env);
void	ft_safe_free(void **ptr);

//EXTRACT_COMMAND.C
char	**extract_command(t_exec *exec, int i);

//EXECUTE_EXIT.C
int		execute_exit(char **command, t_env *env);

//FIRST_REDIRECTION.C
int		check_first_redirection(t_exec *exec, t_data *data);
char	**first_is_delimiter(char **command, t_exec *exec, t_data *data);

//-----------------LIST FUNCTIONS-----------------------//
//LIST_COMMAND.C
t_cmds	*list_cmd(t_cmds *command, char **words, t_data *data);

//LIST_COMMAND_UTILS.C
int		init_word(char *word);
int		word_len(char *word);
int		find_last_sym(char *word);
char	*m_find_word(char *line);
int		next_word(char *word, int i);

//LIST_MINI.C
t_cmds	*m_lst_intnew(char *com);
t_cmds	*m_lstlast(t_cmds *lst);
void	m_lstadd_front(t_cmds **lst, t_cmds *cmd);
void	m_lstadd_back(t_cmds **lst, t_cmds *cmd);
void	m_lstadd_back_quote(t_cmds **lst, t_cmds *cmd, int quote);
int		m_lstsize(t_cmds *lst);
void	m_listclear(t_cmds **lst, void (*del)(void *));

//------------------------MAKE CHARS--------------------//
//MAKE_PIPE.C
void	make_pipe(char **command, t_env *env, t_data *data);
void	close_pipe(int pipe_fd[2], t_data *data);
void	pipe_exception(t_data *data);

//MAKE_INPUT.C <
t_cmds	*make_input(char **command, t_env *env, t_cmds	*node, t_data *data);
int		first_argument_input(char *file);

//MAKE_OUTPUT.C >
void	make_output(char **command, t_env *env, char *file, t_data *data);
t_cmds	*first_argument_output(t_cmds *node);
t_cmds	*last_file_output(t_cmds *node);
t_cmds	*find_last(t_cmds *first, t_cmds *last);

//MAKE_APPEND.C >>
void	make_append(char **command, t_env *env, char *file, t_data *data);
t_cmds	*first_argument_append(t_cmds *node);

//MAKE_DELIMITER.C <<
t_cmds	*make_delimiter(char **command, t_env *env, t_cmds *node, t_data *data);
char	**first_delimiter(char **command);

//PIPE_DELIMITER.C
t_cmds	*case_pipe(t_data *data, t_cmds *node);
void	pipe_delimiter(t_data *data);

//MAKE_HERE_DOC.C <<
void	replace_here_doc(t_cmds *now);

//-----------------------UTILS-----------------------//
//EXIT_MINI.C
void	free_execve(char **command, t_env *env, char **envp, char *route);
void	free_fork(char **command, t_env *env);
void	exit_mini(char *line, t_env *env);

//FD_UTILS.C
void	restaure_fd(t_data *data);
void	save_fd(t_data *data);

//FT_JOINCHAR.C
char	*ft_joinchar(char *str, char c);

//FT_HAVE_THIS.C
int		ft_have_this(char *word, int this);

//-----------------------LEXER FUNCTIONS-----------------------//
int		lexer(char *words);

#endif
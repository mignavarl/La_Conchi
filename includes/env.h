#ifndef ENV_H
# define ENV_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
//# include <minishell.h>
# include "../libft/libft.h"

typedef struct s_env
{
    char *key;
    char *value;
    struct s_env *next;
} t_env;

// Declaraciones de funciones
//ENV.C
t_env	    *init_env(char **envp, t_env *env);
void	    add_env_var(t_env **env_list, char *key, char *value);
char	    *get_env_var(t_env *env_list, char *key);
void	    update_env_var(t_env **env_list, char *key, char *value);
void	    remove_env_var(t_env **env_list, char *key);

//ENV_UTILS.C
int		    env_lstsize(t_env *lst);
t_env	    *env_last(t_env *lst);
void	    env_add_back(t_env **lst, t_env *new);
void	    free_env(t_env *env_list);

//BUIILTINS
//void            ft_myprintecho(char *echo, int flag);
//static int      ft_myecho(char *echo);
//t_list	        *builtins(void);
//static int	    echo_aux(char *prompt);
//int	            terminator(t_tools *tools, char *prompt, int blt);
//void	        get_builts(t_string *built, unsigned int i);
//int	            ft_myunset(t_tools *tools, char *name);
//int	            ft_myexport(t_tools *tools, char *prompt);
//char	        *prsstraux(char *aux, char *str, unsigned int *i, t_tools *tools);
//int	            iter_str(char c);
//static void	    ft_printenvp_ii(char *str, int *flag);
//void	        ft_printenvp(t_tools *tools);
//int	            ft_strcmp(char *str1, char *str2);
//int	            ft_customenvp(t_tools *tools);
//char	        *ft_searchqu(char *str, char c, unsigned int *i, t_tools *tools);

#endif

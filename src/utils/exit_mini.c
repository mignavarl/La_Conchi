#include "minishell.h"

void	free_execve(char **command, t_env *env, char **envp, char *route)
{
	ft_free_double(&command);
	free_env(env);
	ft_free_double(&envp);
	free(route);
	exit(127);
}

void	free_fork(char **command, t_env *env)
{
	ft_putendl_fd("Fork error", 1);
	ft_free_double(&command);
	free_env(env);
}

void	exit_mini(char *line, t_env *env)
{
	ft_putendl_fd("exit", 2);
	free(line);
	free_env(env);
	exit(0);
}

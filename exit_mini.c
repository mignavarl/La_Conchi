#include "prueba_mini.h"

void	free_execve(char **command, t_env *env, char **envp, char *route)
{
	ft_free_double(command);
	free_env(env);
	ft_free_double(envp);
	free(route);
	exit(0);
}

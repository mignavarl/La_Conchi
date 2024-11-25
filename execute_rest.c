#include "prueba_mini.h"

void	execute_rest(char **command, t_env *env)
{
	char	**envp;
	char	*route;
	pid_t	pid;

	envp = set_env(env);
	route = search_route(command[0], envp);
	pid = fork();
	if (pid < 0)
		perror("Fork mal hecho");
	if (pid == 0)
	{
		execve(route, command, envp);
		//TODO: si falla execve liberar
		printf("%s: command not found\n", command[0]);
		free_execve(command, env, envp, route);
	}
	else
	{
		ft_free_double(envp);
		free(route);
	}
}

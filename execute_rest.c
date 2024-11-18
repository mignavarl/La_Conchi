#include "prueba_mini.h"

void	execute_rest(char **command, t_env *env)
{
	char	*route;
	char	**envp;
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
		exit(0);
	}
}

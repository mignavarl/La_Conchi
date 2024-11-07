#include "prueba_mini.h"

void	child(char **command)
{
	char	*route;

	//route = search_route(command[0]);//TODO: y el envp
	execve(route, command, );
}

void	make_pipe(char **command)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid < 0)
		perror("Fork mal hecho");//TODO:funcion para salir
	if (pid == 0)
	{
		close(pipefd[READ]);
		dup2(pipefd[WRITE], STDOUT_FILENO);
		close(pipefd[WRITE]);
		child(command);
	}
	else
	{
		close(pipefd[WRITE]);
		dup2(pipefd[READ], STDIN_FILENO);
		close(pipefd[READ]);
	}
}

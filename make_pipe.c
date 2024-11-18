#include "prueba_mini.h"

void	close_pipe(int pipe_fd[2], t_data *data)
{
	if (pipe_fd[READ] || pipe_fd[WRITE])
	{
		close(pipe_fd[READ]);
		close(pipe_fd[WRITE]);
		dup2(data->clon_stdin, STDIN_FILENO);
		dup2(data->clon_stdout, STDOUT_FILENO);
		close(data->clon_stdin);
		close(data->clon_stdout);
	}
}

void	child(char **command, t_env *env)
{
	char	**envp;
	char	*route;

	envp = set_env(env);
	route = search_route(command[0], envp);
	execve(route, command, envp);
}

void	make_pipe(char **command, t_env *env, t_data *data)
{
	pid_t	pid;

	pipe(data->pipe_fd);
	pid = fork();
	if (pid < 0)
		perror("Fork mal hecho");//TODO:funcion para salir
	if (pid == 0)
	{
		close(data->pipe_fd[READ]);
		dup2(data->pipe_fd[WRITE], STDOUT_FILENO);
		close(data->pipe_fd[WRITE]);
		child(command, env);
	}
	else
	{
		close(data->pipe_fd[WRITE]);
		dup2(data->pipe_fd[READ], STDIN_FILENO);
		close(data->pipe_fd[READ]);
	}
}

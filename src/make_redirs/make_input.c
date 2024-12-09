#include "minishell.h"

void	make_input(char **command, t_env *env, char *file)
{
	int		fd_input;
	pid_t	pid;

	fd_input = open(file, O_RDONLY);
	if (fd_input < 0)
	{
		printf("La Conchi says: no such file or directory: %s\n", file);
		return ;
	}
	pid = fork();
	if (pid < 0)
		perror("Fork mal hecho");//TODO:funcion para salir
	if (pid == 0)
	{
		dup2(fd_input, STDIN_FILENO);
		close(fd_input);
		child(command, env);
	}
	else
		close(fd_input);
}

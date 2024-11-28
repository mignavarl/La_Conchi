#include "prueba_mini.h"

void	first_argument_output(char *file)
{
	int		fd_output;

	fd_output = open(file, O_WRONLY | O_TRUNC | O_CREAT, 00644);
	dup2(fd_output, STDOUT_FILENO);
	close(fd_output);
}

void	make_output(char **command, t_env *env, char *file)
{
	int		fd_output;
	pid_t	pid;

	fd_output = open(file, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd_output < 0)
	{
		printf("Error outfile\n");//Mensaje provisional
		return ;
	}
	pid = fork();
	if (pid < 0)
		perror("Fork mal hecho");//TODO:funcion salir
	if (pid == 0)
	{
		dup2(fd_output, STDOUT_FILENO);
		close(fd_output);
		child(command, env);
	}
	else
	{
		ft_free_double(command);
		close(fd_output);
	}
}

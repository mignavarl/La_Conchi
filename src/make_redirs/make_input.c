/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 10:31:50 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-10 10:31:50 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	first_argument_input(char *file)
{
	int		fd_input;

	fd_input = open(file, O_RDONLY);
	if (fd_input < 0)
	{
		ft_putstr_fd("La Conchi says: no such file or directory:", 1);
		ft_putendl_fd(file, 1);
		return (0);
	}
	dup2(fd_input, STDIN_FILENO);
	close(fd_input);
	return (1);
}

void	make_input(char **command, t_env *env, char *file)
{
	int		fd_input;
	pid_t	pid;

	fd_input = open(file, O_RDONLY);
	if (fd_input < 0)
	{
		ft_putstr_fd("La Conchi says: no such file or directory:", 1);
		ft_putendl_fd(file, 1);
		return ;
	}
	pid = fork();
	if (pid < 0)
		perror("Fork mal hecho");//TODO:funcion para salir
	if (pid == 0)
	{
		dup2(fd_input, STDIN_FILENO);
		close(fd_input);
		execute_cmd(command, env, pid);
	}
	else
		close(fd_input);
}

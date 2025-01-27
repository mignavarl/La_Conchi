/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-19 11:15:46 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-19 11:15:46 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_append(char **command, t_env *env, char *file, t_data *data)
{
	int		fd_append;
	pid_t	pid;

	fd_append = open(file, O_WRONLY | O_CREAT | O_APPEND, 00644);
	if (fd_append < 0)
	{
		ft_putstr_fd("La Conchi says: no such file or directory:", 1);
		ft_putendl_fd(file, 1);
		return ;
	}
	pid = fork();
	if (pid < 0)
		free_fork(command, env);
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		dup2(fd_append, STDOUT_FILENO);
		close(fd_append);
		execute_cmd(command, env, pid, data);
	}
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		perror("Signal");
	else
		close(fd_append);
}

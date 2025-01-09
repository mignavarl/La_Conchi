/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 10:31:59 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-10 10:31:59 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipe(int pipe_fd[2], t_data *data)
{
	if (data->to_close == 1)
	{
		close(pipe_fd[READ]);
		close(pipe_fd[WRITE]);
		dup2(data->clon_stdin, STDIN_FILENO);
		dup2(data->clon_stdout, STDOUT_FILENO);
		close(data->clon_stdin);
		close(data->clon_stdout);
		data->to_close = 0;
	}
}

void	make_pipe(char **command, t_env *env, t_data *data)
{
	pid_t	pid;

	pipe(data->pipe_fd);
	pid = fork();
	if (pid < 0)
		free_fork(command, env);
	if (pid == 0)
	{
		close(data->pipe_fd[READ]);
		dup2(data->pipe_fd[WRITE], STDOUT_FILENO);
		close(data->pipe_fd[WRITE]);
		execute_cmd(command, env, pid);
	}
	else
	{
		close(data->pipe_fd[WRITE]);
		dup2(data->pipe_fd[READ], STDIN_FILENO);
		close(data->pipe_fd[READ]);
		ft_free_double(command);
	}
}

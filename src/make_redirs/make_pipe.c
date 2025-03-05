/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:31:59 by mignavar          #+#    #+#             */
/*   Updated: 2025/03/04 15:57:41 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_exception(t_data *data)
{
	int	fd_pipe[2];

	pipe(fd_pipe);
	close(fd_pipe[WRITE]);
	dup2(fd_pipe[READ], STDIN_FILENO);
	close(fd_pipe[READ]);
	data->to_close = 1;
}

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
		signal(SIGQUIT, SIG_DFL);
		close(data->pipe_fd[READ]);
		dup2(data->pipe_fd[WRITE], STDOUT_FILENO);
		close(data->pipe_fd[WRITE]);
		execute_cmd(command, env, pid, data);
	}
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		perror("Signal");
	if (pid != 0)
	{
		close(data->pipe_fd[WRITE]);
		dup2(data->pipe_fd[READ], STDIN_FILENO);
		close(data->pipe_fd[READ]);
		ft_free_double(&command);
	}
}

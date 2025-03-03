/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_delimiter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-03 13:39:44 by mignavar          #+#    #+#             */
/*   Updated: 2025-03-03 13:39:44 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_delimiter(t_data *data)
{
	pipe(data->pipe_fd);
	dup2(data->pipe_fd[WRITE], STDOUT_FILENO);
	close(data->pipe_fd[WRITE]);
	data->to_close = 1;
}

t_cmds	*case_pipe(t_data *data, t_cmds *node)
{
	dup2(data->pipe_fd[READ], STDIN_FILENO);
	close(data->pipe_fd[READ]);
	dup2(data->clon_stdout, STDOUT_FILENO);
	return (node->next);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 10:31:54 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-10 10:31:54 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmds	*find_last(t_cmds *first, t_cmds *last)
{
	int	fd;

	fd = open(first->cmd, O_WRONLY | O_TRUNC | O_CREAT, 00644);
	close(fd);
	while(1)
	{
		if (!ft_strcmp(last->cmd, ">"))
		{
			first = last->next;
			fd = open(first->cmd, O_WRONLY | O_TRUNC | O_CREAT, 00644);
			close(fd);
			if (first->next)
			{
				last = first->next;
				if (ft_strcmp(last->cmd, ">"))
					return (first);
			}
			else
				return (first);
		}
	}
	return (first);
}

t_cmds	*last_file_output(t_cmds *node)
{
	t_cmds	*first;
	t_cmds	*last;

	first = node;
	if (first->next)
	{
		last = first->next;
		if (ft_strcmp(last->cmd, ">"))
			return (node);
	}
	else
		return (node);
	first = find_last(first, last);
	return (first);
}

t_cmds	*first_argument_output(t_cmds *node)
{
	int		fd_output;
	t_cmds	*next;

	fd_output = open(node->cmd, O_WRONLY | O_TRUNC | O_CREAT, 00644);
	dup2(fd_output, STDOUT_FILENO);
	close(fd_output);
	if (node->next && !ft_strcmp(node->next->cmd, ">"))
	{
		next = last_file_output(node);
		fd_output = open(next->cmd, O_WRONLY | O_TRUNC | O_CREAT, 00644);
		dup2(fd_output, STDOUT_FILENO);
		close(fd_output);
		return (next);
	}
	else
		return (node);
}

void	make_output(char **command, t_env *env, char *file)
{
	int		fd_output;
	pid_t	pid;

	fd_output = open(file, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd_output < 0)
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
		dup2(fd_output, STDOUT_FILENO);
		close(fd_output);
		execute_cmd(command, env, pid);
	}
	else
		close(fd_output);
}

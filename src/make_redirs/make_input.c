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

t_cmds	*check_pipe(t_cmds *node)
{
	t_cmds	*last;

	if (!node->next)
		return (node);
	last = node->next;
	if (!ft_strcmp(last->cmd, "|"))
		return (last);
	return (node);
}

t_cmds	*find_output_from_in(t_cmds *last)
{
	int		fd_out;
	t_cmds	*node;

	ft_putendl_fd(" ", 1);
	while (1)
	{
		ft_putendl_fd(last->cmd, 1);
		if (!ft_strcmp(last->cmd, ">"))
		{
			node = last->next;
			
			fd_out = open(node->cmd, O_WRONLY | O_TRUNC | O_CREAT, 00644);		
			if (node->next)
				last = node->next;
			else
				break ;
		}
		else
			break ;
		close(fd_out);
	}
	ft_putendl_fd(" ", 1);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	node = check_pipe(node);
	return (node);
}

t_cmds	*make_input(char **command, t_env *env, char *file, t_cmds* node)
{
	int		fd_input;
	pid_t	pid;

	fd_input = open(file, O_RDONLY);
	if (node->next && !ft_strcmp(node->next->cmd, ">"))
		node = find_output_from_in(node->next);
	if (fd_input < 0)
	{
		ft_putstr_fd("La Conchi says: no such file or directory:", 1);
		ft_putendl_fd(file, 1);
		return (node);
	}
	pid = fork();
	if (pid < 0)
		free_fork(command, env);
	if (pid == 0)
	{
		dup2(fd_input, STDIN_FILENO);
		close(fd_input);
		execute_cmd(command, env, pid);
	}
	else
		close(fd_input);
	return (node);
}

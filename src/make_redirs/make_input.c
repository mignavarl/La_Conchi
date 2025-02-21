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
		ft_putstr_fd("La Conchi says: no such file or directory: ", 2);
		ft_putendl_fd(file, 2);
		return (0);
	}
	dup2(fd_input, STDIN_FILENO);
	close(fd_input);
	return (1);
}

t_cmds	*find_output_from_in(t_cmds *last)
{
	int		fd_out;
	t_cmds	*node;

	while (!ft_strcmp(last->cmd, ">"))
	{
		if (!ft_strcmp(last->cmd, ">"))
		{
			node = last->next;
			fd_out = open(node->cmd, O_WRONLY | O_TRUNC | O_CREAT, 00644);
			close(fd_out);
			if (node->next)
				last = node->next;
			else
				break ;
		}
		else
			break ;
	}
	fd_out = open(node->cmd, O_WRONLY | O_TRUNC | O_CREAT, 00644);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	return (node);
}

t_cmds	*no_input_make_input(t_cmds *node, char *file)
{
	ft_putstr_fd("La Conchi says: no such file or directory: ", 2);
	ft_putendl_fd(file, 2);
	return (node);
}

t_cmds	*make_input(char **command, t_env *env, t_cmds *node, t_data *data)
{
	int		fd_input;
	pid_t	pid;
	char	*file;

	file = node->cmd;
	fd_input = open(file, O_RDONLY);
	if (node->next && !ft_strcmp(node->next->cmd, ">"))
		node = find_output_from_in(node->next);
	if (fd_input < 0)
		return (no_input_make_input(node, file));
	pid = fork();
	if (pid < 0)
		free_fork(command, env);
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		dup2(fd_input, STDIN_FILENO);
		close(fd_input);
		execute_cmd(command, env, pid, data);
	}
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		perror("Signal");
	else
		close(fd_input);
	return (node);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_delimiter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-23 17:54:33 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-23 17:54:33 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmds	*find_output(t_cmds *node, t_data *data)
{
	t_cmds	*next;
	int		fd_out;

	if (!node->next)
		return (node);
	next = node->next;
	if (!ft_strcmp(next->cmd, ">"))
	{
		next = next->next;
		fd_out = open(next->cmd, O_WRONLY | O_TRUNC | O_CREAT, 00644);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
	if (!ft_strcmp(next->cmd, "|"))
	{
		pipe_delimiter(data);
		return (node);
	}
	return (next);
}

void	error_delimiter(char *cmd)
{
	ft_putstr_fd("La Conchi says: no such file or directory:", 2);
	ft_putendl_fd(cmd, 2);
}

t_cmds	*last_delimiter(t_cmds *node)
{
	t_cmds	*first;
	t_cmds	*last;

	first = node;
	last = node->next;
	while (last && !ft_strcmp(last->cmd, "<<"))
	{
		if (last->next)
			first = last->next;
		else
			return (first);
		if (first->next)
			last = first->next;
		else
			return (first);
	}
	return (first);
}

t_cmds	*make_delimiter(char **command, t_env *env, t_cmds *node, t_data *data)
{
	int		fd_delim;
	pid_t	pid;

	node = last_delimiter(node);
	fd_delim = open(node->cmd, O_RDONLY);
	node = find_output(node, data);
	if (fd_delim < 0)
		return (error_delimiter(node->cmd), NULL);
	pid = fork();
	if (pid < 0)
		free_fork(command, env);
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		dup2(fd_delim, STDIN_FILENO);
		close(fd_delim);
		execute_cmd(command, env, pid, data);
	}
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		perror("Signal");
	else
		close(fd_delim);
	if (node->next && node->next->cmd[0] == '|')
		node = case_pipe(data, node);
	return (node);
}

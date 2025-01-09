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

t_cmds	*find_output(t_cmds *node)
{
	t_cmds *next;
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
	return (next);
}

t_cmds	*make_delimiter(char **command, t_env *env, char *eof, t_cmds *node)
{
	int		fd_delim;
	pid_t	pid;

	fd_delim = open(eof, O_RDONLY);
	node = find_output(node);
	if (fd_delim < 0)
	{
		ft_putstr_fd("La Conchi says: no such file or directory:", 1);
		ft_putendl_fd(eof, 1);
		return (NULL);
	}
	pid = fork();
	if (pid < 0)
		free_fork(command, env);
	if (pid == 0)
	{
		dup2(fd_delim, STDIN_FILENO);
		close(fd_delim);
		execute_cmd(command, env, pid);
	}
	else
		close(fd_delim);
	return (node);
}

char	**create_new_cmd(char **command, char **new_cmd, int c)
{
	int	n;

	n = 0;
	while (command[c])
	{
		new_cmd[n] = ft_strdup(command[c]);
		c++;
		n++;
	}
	new_cmd[n] = NULL;
	return (new_cmd);
}

char	**first_delimiter(char **command)
{
	char	**new_cmd;
	int		c;
	int		fd_delim;

	c = 1;
	while (command[c])
		c++;
	if (c <= 2)
	{
		ft_free_double(command);
		return (NULL);
	}
	new_cmd = malloc(c * sizeof(char *));
	if (!new_cmd)
		return (NULL);
	fd_delim = open(command[1], O_RDONLY);
	dup2(fd_delim, STDIN_FILENO);
	close(fd_delim);
	c = 2;
	new_cmd = create_new_cmd(command, new_cmd, c);
	ft_free_double(command);
	return (new_cmd);
}

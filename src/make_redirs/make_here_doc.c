/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:42:33 by mignavar          #+#    #+#             */
/*   Updated: 2025/03/01 16:16:58 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	while_here_doc(t_cmds *search, int delim)
{
	t_cmds	*eof;
	char	*line;
	char	*tmp_file;
	int		fd;

	eof = search->next;
	line = ft_itoa(delim);
	tmp_file = ft_strjoin("/tmp/tmp", line);
	free(line);
	fd = open(tmp_file, O_RDWR | O_TRUNC | O_APPEND | O_CREAT, 00644);
	while (1)
	{
		line = readline(GREEN"> "END);
		if (!ft_strcmp(line, eof-> cmd) || g_signal_c == 130)
			break ;
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
	}
	g_signal_c = 0;
	free(line);
	close(fd);
	free(eof->cmd);
	eof->cmd = ft_strdup(tmp_file);
	free(tmp_file);
}

void	replace_here_doc(t_cmds *now)
{
	int		delim;
	t_cmds	*search;

	delim = 0;
	search = now;
	while (search)
	{
		if (!ft_strcmp(search->cmd, "<<"))
			delim++;
		search = search->next;
	}
	if (delim == 0)
		return ;
	search = now;
	while (delim > 0 && search)
	{
		if (!ft_strcmp(search->cmd, "<<"))
		{
			while_here_doc(search, delim);
			delim--;
		}
		search = search->next;
	}
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
		ft_free_double(&command);
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
	ft_free_double(&command);
	return (new_cmd);
}

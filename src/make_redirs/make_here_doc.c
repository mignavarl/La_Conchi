/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-08 13:42:33 by mignavar          #+#    #+#             */
/*   Updated: 2025-01-08 13:42:33 by mignavar         ###   ########.fr       */
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
		line = readline(">");
		if (!ft_strcmp(line, eof-> cmd))
			break ;
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
	}
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

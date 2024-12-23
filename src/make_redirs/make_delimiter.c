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

void	while_here_doc(t_cmds *search, int delim)
{
	t_cmds	*eof;
	char	*line;
	char	*tmp_file;
	int		fd;

	eof = search->next;
	tmp_file = ft_threejoin("/tmp/", "tmp", ft_itoa(delim));
	fd = open(tmp_file, O_RDWR | O_TRUNC | O_APPEND | O_CREAT, 00644);
	while (1)
	{
		line = get_next_line(0);
		if (!ft_strcmp(line, eof->cmd))
		ft_putstr_fd(line, fd);
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

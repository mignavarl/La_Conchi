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
	line = ft_itoa(delim);
	tmp_file = ft_strjoin("/tmp/tmp", line);
	free(line);
	fd = open(tmp_file, O_RDWR | O_TRUNC | O_APPEND | O_CREAT, 00644);
	while (1)
	{
		line = get_next_line(0);
		if (!ft_strncmp(line, eof->cmd, ft_strlen(line) - 1))
			break ;
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

void	make_delimiter(char **command, t_env *env, char *file)
{
	int		fd_delim;
	pid_t	pid;

	fd_delim = open(file, O_RDONLY);
	if (fd_delim < 0)
	{
		ft_putstr_fd("La Conchi says: no such file or directory:", 1);
		ft_putendl_fd(file, 1);
		return ;
	}
	pid = fork();
	if (pid < 0)
		perror("Fork mal hecho");//TODO:funcion para salir
	if (pid == 0)
	{
		dup2(fd_delim, STDIN_FILENO);
		close(fd_delim);
		execute_cmd(command, env, pid);
	}
	else
		close(fd_delim);
}

char	**first_delimiter(char **command)
{
	char	**new_cmd;
	int		c;
	int		n;
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
	n = 0;
	while (command[c])
	{
		new_cmd[n] = ft_strdup(command[c]);
		c++;
		n++;
	}
	new_cmd[n] = NULL;
	ft_free_double(command);
	return (new_cmd);
}

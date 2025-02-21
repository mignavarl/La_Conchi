/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-12 15:20:01 by mignavar          #+#    #+#             */
/*   Updated: 2025-02-12 15:20:01 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_com(t_cmds *now)
{
	t_cmds	*tmp;
	int		com;

	tmp = now;
	com = 0;
	if (!ft_strcmp(tmp->cmd, "<<"))
	{
		tmp = tmp->next;
		com++;
		while (tmp && tmp->cmd && !m_ischar(tmp->cmd))
		{
			tmp = tmp->next;
			com++;
		}
	}
	else
	{
		while (tmp && tmp->cmd && (tmp->quote == 1 || !m_ischar(tmp->cmd)))
		{
			tmp = tmp->next;
			com++;
		}
	}
	return (com + 1);
}

char	**extract_command(t_exec *exec, int i)
{
	char	**command;

	command = ft_calloc(count_com(exec->now), sizeof(char *));
	if (!command)
		return (NULL);
	command[0] = ft_strdup(exec->now->cmd);
	if (!command[0])
	{
		ft_free_double(&command);
		return (NULL);
	}
	while (exec->next && exec->next->cmd
		&& (exec->next->quote == 1 || !m_ischar(exec->next->cmd)))
	{
		command[i] = ft_strdup(exec->next->cmd);
		if (!command[i])
		{
			ft_free_double(&command);
			return (NULL);
		}
		exec->next = exec->next->next;
		i++;
	}
	command[i] = NULL;
	return (command);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-12 14:50:38 by mignavar          #+#    #+#             */
/*   Updated: 2025-02-12 14:50:38 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	first_is_output(t_exec *exec, t_data *data)
{
	data->to_close = 1;
	exec->next = first_argument_output(exec->next);
	if (exec->next->next)
	{
		exec->now = exec->next->next;
		if (m_ischar(exec->now->cmd))
		{
			restaure_fd(data);
			exec->now = exec->now->next;
		}
		if (exec->now->next)
			exec->next = exec->now->next;
		else
			exec->next = NULL;
	}
	else
		return (-1);
	return (1);
}

int	first_is_input(t_exec *exec, t_data *data)
{
	data->to_close = 1;
	first_argument_input(exec->next->cmd);
	if (exec->next->next)
	{
		exec->now = exec->next->next;
		if (m_ischar(exec->now->cmd))
		{
			restaure_fd(data);
			exec->now = exec->now->next;
		}
		if (exec->now->next)
			exec->next = exec->now->next;
		else
			exec->next = NULL;
	}
	else
		return (-1);
	return (1);
}

int	check_first_redirection(t_exec *exec, t_data *data)
{
	int	start;

	start = 1;
	if (!ft_strcmp(exec->now->cmd, ">"))
		start = first_is_output(exec, data);
	if (!ft_strcmp(exec->now->cmd, "<"))
		start = first_is_input(exec, data);
	return (start);
}

char	**first_is_delimiter(char **command, t_exec *exec, t_data *data)
{
	if (!ft_strcmp(exec->now->cmd, "<<"))
	{
		data->to_close = 1;
		command = first_delimiter(command);
		if (!command)
			return (NULL);
	}
	return (command);
}

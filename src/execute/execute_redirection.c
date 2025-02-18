/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:31:26 by mignavar          #+#    #+#             */
/*   Updated: 2025/02/18 16:03:50 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_append(char **command, t_exec *exec, t_env *env, t_data *data)
{
	exec->next = exec->next->next;
	make_append(command, env, exec->next->cmd, data);
	if (!exec->next->next)
	{
		ft_free_double(&command);
		return (0);
	}
	ft_free_double(&command);
	return (1);
}

int	execute_delimiter(char **command, t_exec *exec, t_env *env, t_data *data)
{
	exec->next = exec->next->next;
	exec->next = make_delimiter(command, env, exec->next, data);
	if (!exec->next->next)
	{
		ft_free_double(&command);
		return (0);
	}
	ft_free_double(&command);
	return (1);
}

int	execute_input(char **command, t_exec *exec, t_env *env, t_data *data)
{
	exec->next = exec->next->next;
	exec->next = make_input(command, env, exec->next, data);
	if (!exec->next->next)
	{
		ft_free_double(&command);
		return (0);
	}
	ft_free_double(&command);
	return (1);
}

int	execute_output(char **command, t_exec *exec, t_env *env, t_data *data)
{
	exec->next = last_file_output(exec->next->next);
	make_output(command, env, exec->next->cmd, data);
	if (!exec->next->next)
	{
		ft_free_double(&command);
		return (0);
	}
	data->to_close = 1;
	ft_free_double(&command);
	return (1);
}

int	execute_redirection(char **command, t_exec *exec, t_env *env, t_data *data)
{
	int	exit;

	exit = 1;
	data->to_close = 1;
	data->have_redir = 0;
	if (!ft_strcmp(exec->next->cmd, ">>") && exec->next->next)
		exit = execute_append(command, exec, env, data);
	else if (!ft_strcmp(exec->next->cmd, "<<") && exec->next->next)
		exit = execute_delimiter(command, exec, env, data);
	else if (!ft_strcmp(exec->next->cmd, "<") && exec->next->next)
		exit = execute_input(command, exec, env, data);
	else if (!ft_strcmp(exec->next->cmd, ">") && exec->next->next)
		exit = execute_output(command, exec, env, data);
	else if (!ft_strcmp(exec->next->cmd, "|") && exec->next->next)
		make_pipe(command, env, data);
	else
	{
		ft_putendl_fd("La Conchi says: last command not found", 2);
		ft_free_double(&command);
		return (0);
	}
	data->have_redir = 1;
	return (exit);
}

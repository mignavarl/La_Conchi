/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:31:33 by mignavar          #+#    #+#             */
/*   Updated: 2025/03/04 15:16:37 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_now_and_next(t_exec *exec, t_data *data)
{
	if (exec->next->next)
	{
		exec->now = exec->next->next;
		if (!ft_strcmp(exec->now->cmd, "|"))
		{
			pipe_exception(data);
			exec->now = exec->now->next;
		}
	}
	else
		exec->now = NULL;
	if (exec->now && exec->now->next)
		exec->next = exec->now->next;
	else
		exec->next = NULL;
}

int	while_loop_cmd(char **command, int i, t_exec *exec, t_data *data)
{
	command = extract_command(exec, i);
	if (!command)
		return (0);
	command = first_is_delimiter(command, exec, data);
	if (!command)
		return (0);
	if (exec->next && m_ischar(exec->next->cmd) && exec->next->quote == 0)
	{
		if (!execute_redirection(command, exec, exec->env, data))
			return (0);
	}
	else
	{
		execute_cmd(command, exec->env, 1, data);
		return (0);
	}
	return (1);
}

void	loop_cmd(t_exec *exec, t_env *env, t_data *data)
{
	char	**command;
	int		i;

	save_fd(data);
	replace_here_doc(exec->now);
	data->have_redir = 0;
	command = NULL;
	exec->env = env;
	while (exec->now)
	{
		i = check_first_redirection(exec, data);
		if (i == -1)
			break ;
		if (!while_loop_cmd(command, i, exec, data))
			break ;
		update_now_and_next(exec, data);
	}
}

void	execute(t_cmds **cmd, t_env *env, t_data *data)
{
	t_exec	exec;

	ft_bzero(&exec, sizeof(t_exec));
	exec.now = *cmd;
	if (!exec.now)
		return ;
	data->last_exit = 0;
	if (m_lstsize(*cmd) > 1)
	{
		exec.next = exec.now->next;
		loop_cmd(&exec, env, data);
	}
	else
	{
		if (m_ischar(exec.now->cmd))
		{
			ft_putstr_fd("La Conchi says: syntax error near ", 2);
			ft_putendl_fd(exec.now->cmd, 2);
			return ;
		}
		if (exec.now->quote == 1)
			execute_cmd(ft_split(exec.now->cmd, '\0'), env, 1, data);
		else
			execute_cmd(ft_split(exec.now->cmd, ' '), env, 1, data);
	}
}

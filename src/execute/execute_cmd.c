/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:31:04 by mignavar          #+#    #+#             */
/*   Updated: 2025/03/04 14:57:35 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rest(char **command, t_env *env, pid_t pid, t_data *data)
{
	if (pid != 0)
		execute_rest(command, env, data);
	else
		execute_rest_pid(command, env, data);
}

void	builtins(char **command, t_env *env, pid_t pid, t_data *data)
{
	if (!ft_strcmp(command[0], "cd"))
		execute_cd(command, env);
	else if (!ft_strcmp(command[0], "pwd"))
		execute_pwd();
	else if (!ft_strcmp(command[0], "echo"))
		execute_echo(command);
	else if (!ft_strcmp(command[0], "env"))
		execute_env(command, env);
	else if (!ft_strcmp(command[0], "export"))
		execute_export(command, env);
	else if (!ft_strcmp(command[0], "unset"))
		execute_unset(command, env);
	else if (!ft_strcmp(command[0], "exit"))
		execute_exit(command, env);
	else
		rest(command, env, pid, data);
}

void	execute_cmd(char **command, t_env *env, pid_t pid, t_data *data)
{
	if (!command || !env || !command[0])
	{
		ft_free_double(&command);
		return ;
	}
	if (data->have_redir == 1)
	{
		pid = fork();
		if (pid < 0)
			free_fork(command, env);
		if (pid != 0)
		{
			ft_free_double(&command);
			return ;
		}
	}
	builtins(command, env, pid, data);
	if (pid == 0)
		exit(0);
	if (command)
		ft_free_double(&command);
}

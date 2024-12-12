/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 10:31:04 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-10 10:31:04 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_cmd(char **command, t_env *env, pid_t pid)
{
	if (!command || !env)
		return ;//TODO:funcion salir
	if (!ft_strcmp(command[0], "cd"))
		execute_cd(command);
	else if (!ft_strcmp(command[0], "pwd"))
		execute_pwd();
	else
	{
		if (pid != 0)
			execute_rest(command, env);
		else
			execute_rest_pid(command, env);
	}
	if (pid != 0)
	{
		if (command)
			ft_free_double(command);
	}
	else
	{
		ft_free_double(command);
		free_env(env);
		exit(0);
	}
}

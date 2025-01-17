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

int	execute_exit(char **command, t_env *env)
{
	int	w;
	int	i;

	w = 0;
	i = 0;
	while(command[w])
		w++;
	if (w > 2)
		return (write(1, "exit: too many arguments\n", 25));
	if (w == 2)
	{
		while (command[1][i])
		{
			if (!ft_isdigit(command[1][i]))
				return (write(1, "exit: numeric argument required\n", 32));
			i++;
		}
		i = ft_atoi(command[1]);
		ft_free_double(&command);
		free_env(env);;
		exit(i);
	}
	return(0);
}

void	rest(char **command, t_env *env, pid_t pid)
{
	if (pid != 0)
		execute_rest(command, env);
	else
		execute_rest_pid(command, env);
}

void	execute_cmd(char **command, t_env *env, pid_t pid)
{
	if (!command || !env || !command[0])
	{
		ft_free_double(&command);
		return ;//TODO:funcion salir
	}
	if (!ft_strcmp(command[0], "cd"))
		execute_cd(command);
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
		rest(command, env, pid);
	if (pid == 0)
		exit(0);
	if (command)
		ft_free_double(&command);
}

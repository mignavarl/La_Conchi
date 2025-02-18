/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:31:04 by mignavar          #+#    #+#             */
/*   Updated: 2025/02/18 16:29:56 by osredond         ###   ########.fr       */
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
	if (w == 1)
		exit(0);
	else
	{
		while (command[1][i])
		{
			if (!ft_isdigit(command[1][i]) || command[1][i] == '-')
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

void	rest(char **command, t_env *env, pid_t pid, t_data *data)
{
	if (pid != 0)
		execute_rest(command, env, data);
	else
		execute_rest_pid(command, env, data);
}

void	execute_cmd(char **command, t_env *env, pid_t pid, t_data *data)
{
	if (!command || !env || !command[0])
	{
		ft_free_double(&command); // si command = NULL, cerrar la minishell debido al fallo de alojamiento de memoria en malloc del split  
		// Liberar todo y salir de minishell si command es NULL <- resumen
		return ;
	}
	if (data->have_redir == 1)
	{
		pid = fork();
		if (pid < 0)
			perror("Create Fork");
		if (pid != 0)
		{
			ft_free_double(&command);
			return ;
		}
	}
	if (!ft_strcmp(command[0], "cd"))
		execute_cd(command, env);
	else if (!ft_strcmp(command[0], "pwd"))
		execute_pwd();
	else if (!ft_strcmp(command[0], "echo"))
		execute_echo(command, data);
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
	if (pid == 0)
		exit(0);
	if (command)
		ft_free_double(&command);
}

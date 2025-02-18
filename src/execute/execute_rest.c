/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:31:21 by mignavar          #+#    #+#             */
/*   Updated: 2025/02/18 16:06:12 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_rest_pid(char **command, t_env *env, t_data *data)
{
	char	**envp;
	char	*route;

	envp = set_env(env);
	route = search_route(command[0], envp);
	data->last_exit = execve(route, command, envp);
	ft_putstr_fd(command[0], 2);
	ft_putendl_fd(": command not found", 2);
	free_execve(command, env, envp, route);
}

void	execute_rest(char **command, t_env *env, t_data *data)
{
	char	**envp;
	char	*route;
	pid_t	pid;

	envp = set_env(env);
	route = search_route(command[0], envp);
	pid = fork();
	if (pid < 0)
		perror("Create Fork");
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		data->last_exit = execve(route, command, envp);
		ft_putstr_fd(command[0], 2);
		ft_putendl_fd(": command not found", 2);
		free_execve(command, env, envp, route);
	}
	if (signal(SIGINT, SIG_IGN) == SIG_ERR)
		perror("Signal");
	else
	{
		ft_free_double(&envp);
		free(route);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-19 12:09:32 by mignavar          #+#    #+#             */
/*   Updated: 2025-02-19 12:09:32 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_exit(char **command, t_env *env)
{
	int	w;
	int	i;

	w = 0;
	i = 0;
	while (command[w])
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
		free_env(env);
		exit(i);
	}
	return (0);
}

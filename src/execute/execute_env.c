/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-16 10:59:06 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-16 10:59:06 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_env(char **command, t_env *env)
{
	t_env 	*tmp;
	int		i;

	tmp = env;
	i = 0;
	while (command[i])
		i++;
	if (i > 1)
	{
		printf("env: too many arguments\n");
		return ;
	}
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

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

void	execute_export(char **command, t_env *env)
{
	int		w;
	int		i;
	char	*key;
	char	*value;

	w = 0;
	while (command[w])
		w++;
	if (w != 2)
	{
		write(1, "export: too many arguments\n", 28);
		return ;
	}
	i = 0;
	while (command[1][i] != '=' && command[1][i])
		i++;
	key = ft_substr(command[1], 0, i);
	value = ft_substr(command[1], (i + 1), (ft_strlen(command[1]) - i));
	update_env_var(&env, key, value);
	free(key);
	free(value);
}

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
		write(1, "env: too many arguments\n", 25);
		return ;
	}
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

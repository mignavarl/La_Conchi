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

void	execute_unset(char **command, t_env *env)
{
	int	w;


	w = 0;
	while (command[w])
		w++;
	if (w < 2)
	{
		ft_putendl_fd("unset: too many arguments", 2);
		return ;
	}
	w = 1;
	while (command[w])
	{
		remove_env_var(&env, command[w]);
		w++;
	}
}
void	while_export(char **command, t_env *env, int w)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	if (ft_isdigit(command[w][i]))
	{
		while (command[w][i] != '=' && command[w][i])
			i++;
		key = ft_substr(command[w], 0, i);
		ft_putstr_fd("export: ", 2);
		ft_putstr_fd(key, 2);
		ft_putendl_fd(": not a valid identifier", 2);
		free(key);
	}
	else if (command[w][0] == '=' || command[w][0] == '?')
		ft_putendl_fd("export: not a valid identifier", 2);
	else
	{
		while (command[w][i] != '=' && command[w][i])
			i++;
		key = ft_substr(command[w], 0, i);
		value = ft_substr(command[w], (i + 1), (ft_strlen(command[w]) - i));
		update_env_var(&env, key, value);
		free(key);
		free(value);
	}
}

void	execute_export(char **command, t_env *env)
{
	int		w;

	w = 0;
	while (command[w])
		w++;
	if (w == 1)
	{
		ft_putendl_fd("export: too few arguments", 2);
		return ;
	}
	w = 1;
	while (command[w])
	{
		while_export(command, env, w);
		w++;
	}
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
		ft_putendl_fd("env: too many arguments", 2);
		return ;
	}
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

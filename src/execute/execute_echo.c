/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-13 10:22:39 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-13 10:22:39 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_with_n(char **command, int w)
{
	while (command[w])
	{
		printf("%s", command[w]);
		w++;
		if (command[w])
			printf(" ");
	}
}

void	echo_normal(char **command)
{
	int	w;

	w = 1;
	while (command[w])
	{
		printf("%s ", command[w]);
		w++;
	}
	printf("\n");
}

int	check_n_flag(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n' && str[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_size_array_double(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

void	execute_echo(char **command)
{
	int	w;

	if (ft_size_array_double(command) < 2)
	{
		printf("\n");
		return ;
	}
	w = 1;
	if (!ft_strncmp(command[w], "-n", 2))
	{
		while (command[w] && !ft_strncmp(command[w], "-n", 2))
		{
			if (!check_n_flag(command[w]))
			{
				echo_with_n(command, w);
				return ;
			}
			w++;
		}
		echo_with_n(command, w);
	}
	else
		echo_normal(command);
}

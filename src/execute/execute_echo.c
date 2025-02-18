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

void	echo_with_n(char **command)
{
	int	w;

	w = 0;
	while (command[w])
		w++;
	if (w < 3)
		return ;
	w = 2;
	while (command[w])
	{
		printf("%s ", command[w]);
		w++;
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

void	execute_echo(char **command)
{
	int	w;
	int	i;

	w = 0;
	i = 0;
	while (command[w])
		w++;
	if (w < 2)
	{
		printf("\n");
		return ;
	}
	w = 1;
	if (command[w][0] == '-')
	{
		i = 1;
		while (command[w][i] == 'n')
			i++;
		if (command[w][i] != 'n' && command[w][i] == '\0')
			echo_with_n(command);
	}
	else
		echo_normal(command);
}

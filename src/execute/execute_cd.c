/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 10:30:55 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-10 10:30:55 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_cd(char **command)
{
	int	i;

	i = 0;
	while (command[i])
		i++;
	if (i == 1)
	{
		printf("cd: no argument\n");
		return ;
	}
	if (i != 2)
	{
		printf("cd: too many arguments\n");
		return ;
	}
	if (chdir(command[1]) == -1)
		printf("cd: %s: No such file or directory\n", command[1]);
}

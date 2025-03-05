/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:40:48 by osredond          #+#    #+#             */
/*   Updated: 2025/02/17 20:07:10 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lexer(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '|' && line[i + 1] == '|')
		{
			ft_putendl_fd(
				"La Conchi: syntax error near unexpected token `|'",
				2);
			return (free(line), EXIT_FAILURE);
		}
		else if (line[i] == '|' && !line[i + 1])
		{
			ft_putendl_fd("La Conchi: syntax error near unexpected token `|'",
				2);
			return (free(line), EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

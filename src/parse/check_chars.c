/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 10:32:06 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-10 10:32:06 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Return: 0 = no char. 1 = | < >. 2 = >> <<
int	m_ischar(char *c)
{
	if (c == NULL || (c[0] == '\0'))
		return 0;
	if (ft_strlen(c) > 1)
	{
		if ((ft_strncmp(c, APPEND, 2) == 0 || ft_strncmp(c, DELIMITER, 2) == 0) &&
			(c[2] != PIPE && c[2] != INPUT && c[2] != OUTPUT))
		{
			return (2);
		}
	}
	if ((c[0] == PIPE || c[0] == INPUT || c[0] == OUTPUT))
	{
		return (1);
	}
	return (0);
}


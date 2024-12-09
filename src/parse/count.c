/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-04 10:38:02 by mignavar          #+#    #+#             */
/*   Updated: 2024-10-04 10:38:02 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_end_quote(char *line, int i)
{
	int		l;

	l = i + 1;
	while (line[l])
	{
		if (line[l] == line[i])
			return (l - i);
		l++;
	}
	return (-1);
}

int	count_end_word(char *line, int i)
{
	int	l;

	l = i;
	while (line[l])
	{
		if (line[l] == ' ' || line[l] == '"' || line[l] == '\'')
			return (l - i);
		l++;
	}
	return (l - i);
}

int	count_words(char *line)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (line[i])
	{
		if ((line[i] != '"' && line[i] != '\'' && line[i] != ' '))
		{
			i += count_end_word(line, i);
			word++;
		}
		if (line[i] == '"' || line[i] == '\'')
		{
			if (count_end_quote(line, i) < 0)
				return (-1);
			i += count_end_quote(line, i);
			word++;
		}
		if (line[i] == '\0')
			break ;
		i++;
	}
	return (word);
}

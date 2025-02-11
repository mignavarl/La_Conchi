/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:38:02 by mignavar          #+#    #+#             */
/*   Updated: 2025/01/15 12:58:04 by osredond         ###   ########.fr       */
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
			return (l);
		l++;
	}
	return (-1);
}

int	count_end_word(char *line, int i)
{
	int	l;
	int	q;

	l = i;
	while (line[l])
	{
		if ((line[l] == '"' || line[l] == '\''))
		{
			q = count_end_quote(line, l);
			if (q < 0)
				return (-1);
			l = q + 1;
		}
		if (line[l] == ' ' || line[l] == '\0')
			return (l);
		l++;
	}
	return (l);
}

int	while_count_words(char *line, int i, int word, int q)
{
	while (line[i])
	{
		if (line[i] == ' ' && line[i + 1] != ' ')
			word++;
		if ((line[i] != '"' && line[i] != '\'' && line[i] != ' '))
		{
			q = count_end_word(line, i);
			if (q < 0)
				return (-1);
			i = q;
			word++;
		}
		if (line[i] == '"' || line[i] == '\'')
		{
			q = count_end_quote(line, i);
			if (q < 0)
				return (-1);
			i = q; 
			word++;
		}
		if (line[i] == '\0')
			break ;
		i++;
	}
	return (word);
}

int	count_words(char *line)
{
	int	i;
	int	word;
	int	q;

	i = 0;
	word = 0;
	q = 0;
	word = while_count_words(line, i, word, q);
	if (word < 0)
		return (-1);
	return (word + 1);
}

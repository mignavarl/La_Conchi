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
//TODO: DESUSO ---- BOORRAR
int	count_end_quote(char *line, int i)
{
	int		l;

	l = i + 1;
	while (line[l])
	{
		printf("end quote: %d = %c\n", l, line[l]);
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
			printf("end word: %d = %c\n", l, line[l]);
			q = count_end_quote(line, l);
			if (q < 0)
				return (-1);
			l = q + 1;
		}
		if (line[l] == ' ')
			return (l);
		l++;
	}
	return (l);
}

int	count_words(char *line)
{
	int	i;
	int	word;
	int	q;

	i = 0;
	word = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			word++;
		//i++;
		if ((line[i] != '"' && line[i] != '\'' && line[i] != ' '))
		{
			printf("count word: %d = %c\n", i, line[i]);
			q = count_end_word(line, i);
			if (q < 0)
				return (-1);
			i = q;
			word++;
		}
		if (line[i] == '"' || line[i] == '\'')
		{
			printf("count quote: %d = %c\n", i, line[i]);
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
	return (word + 1);
}

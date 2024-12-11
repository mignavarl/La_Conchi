/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 10:32:26 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-10 10:32:26 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *find_words(char *line, int i, t_data *data)
{
	int		l;
	char	*word;
	char	*tmp_word;

	l = i;
	while(line[l])
	{
		if (line[l] == ' ' || line[l] == '\0' || line[l] == '"' || line[l] == '\'')
			break ;
		l++;
	}
	word = ft_substr(line, i, (l - i));
	if (!word)
		return (NULL);
	if (line[l] && (line[l] == '"' || line[l] == '\''))
	{
		while (line[l])
		{
			if (line[l] != '"' && line[l] != '\'')
			{
				tmp_word = ft_strdup(word);
				if (!word)
					return (NULL);
				free(word);
				word = ft_joinchar(tmp_word, line[l]);
				if (!word)
					return (NULL);
			}
			l++;
		}
	}
	data->quote_chars = l;
	return (word);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 10:32:21 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-10 10:32:21 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**search_in_line(char *line, t_data *data)
{
	int		i;
	int		w;
	int		num_words;  
	char	**words;

	(void)data;//temporal
	i = 0;
	num_words = count_words(line);
	if (num_words < 0)
	{
		printf(RED"Close the quotes\n"END);
		return (NULL);
	}
	words = (char **)ft_calloc(num_words + 1, sizeof(char *));
	w = 0;
	if (line[0] == '\0')
	{
		words[0] = '\0';
		return(words);
	}
	while (line && line[i])
	{
		if (line[i] != '"' && line[i] != '\'' && line[i] != ' ')
		{
			words[w] = find_words(line, i);
			if (!words[w])
				break ;
			i += ft_strlen(words[w]) - 1;
			w++;
		}
		else if (line[i] == '"' || line[i] == '\'')
		{
			words[w] = find_quote(line, i, data);
			if (!words[w])
				break ;
			i += ft_strlen(words[w]);
			//i = data->quote_chars - 1;
			if ((line[i] != ' ' || line[i] != '"' || line[i] != '\'') && line[i])
				i++;
			printf(RED"Word[%d] = %s\nline[%d] = %c\n"END, w, words[w], i, line[i]);
			w++;
		}
		i++;
	}
	w = 0;
	while (w < num_words)
	{
		printf("Word [%d] = %s / %d\n", w, words[w], w);
		w++;
	}
	return (words);
}

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

char	**search_in_line(char *line, t_data *data, t_env *env)
{
	int		i;
	int		w;
	int		num_words;  
	char	**words;

	i = 0;
	num_words = count_words(line);
	if (num_words < 0)
	{
		printf(RED"Close the quotes\n"END);
		return (NULL);
	}
	if (num_words == 1)
		return (NULL);
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
			words[w] = find_words(line, i, data);
			if (!words[w])
				break ;
			i = data->quote_chars - 1;
			w++;
		}
		else if (line[i] == '"' || line[i] == '\'')
		{
			words[w] = find_quote(line, i, data);
			if (!words[w])
				break ;
			i = data->quote_chars;
			printf("words = %s\ndata->quote_chars = %d\n", words[w], data->quote_chars);
			if ((line[i] != ' ' || line[i] != '"' || line[i] != '\'') && line[i] && line[i + 1] != '\0')
				i++;
			if (!line[i])
				break ;
			w++;
		}
		i++;
	}
	(void)env;
	//words = clean_and_expand(words, env, data);
	w = 0;//TODO: borrar, para ver words
	while (w < num_words)
	{
		printf("Word [%d] = %s / %d\n", w, words[w], w);
		w++;
	}
	return (words);
}

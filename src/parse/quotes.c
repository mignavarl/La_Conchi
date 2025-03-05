/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 10:32:15 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-10 10:32:15 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	search_end_quote(char *line, int i)
{
	int		f;
	char	sym;

	f = i + 1;
	sym = line[i];
	while (line[f])
	{
		if (line[f] == sym)
		{
			return (1);
		}
		f++;
	}
	return (0);
}

char	*extract_quote(char *line, char *quote, int init, t_data *data)
{
	char	*new_line;
	char	*new_quote;
	int		q;
	int		n;

	q = init + 1;
	while (line[q] != line[init])
		q++;
	new_line = ft_calloc((q - init) + 2, sizeof(char));
	if (!new_line)
		return (NULL);
	q = init + 1;
	n = 1;
	new_line[0] = line[init];
	while (line[q] != line[init])
		new_line[n++] = line[q++];
	new_line[n] = line[q];
	new_quote = ft_strjoin(quote, new_line);
	free(quote);
	free(new_line);
	data->quote_chars = q + 1;
	return (new_quote);
}

char	*extract_line(char *line, char *quote, int init, t_data *data)
{
	char	*new_line;
	char	*new_space;
	int		q;
	int		n;

	q = init + 1;
	while (line[q] && line[q] != ' ' && line[q] != '"' && line[q] != '\'')
		q++;
	new_line = ft_calloc((q - init) + 1, sizeof(char));
	if (!new_line)
		return (NULL);
	q = init;
	n = 0;
	while (line[q] && line[q] != ' ' && line[q] != '"' && line[q] != '\'')
	{
		new_line[n] = line[q];
		q++;
		n++;
	}
	new_space = ft_strjoin(quote, new_line);
	free(new_line);
	free(quote);
	data->quote_chars = q;
	return (new_space);
}

char	*find_more_quotes(char *line, int l, char *quote, t_data *data)
{
	int	init;

	init = l + 1;
	while (line[init] && line[l])
	{
		if (line[init] == ' ' || line[init] == '\0')
		{
			data->quote_chars = init + 1;
			return (quote);
		}
		if (line[init] == '"' || line[init] == '\'')
			quote = extract_quote(line, quote, init, data);
		else
			quote = extract_line(line, quote, init, data);
		init = data->quote_chars;
	}
	return (quote);
}

char	*find_quote(char *line, int init, t_data *data)
{
	int		l;
	char	*quote;

	l = init + 1;
	quote = NULL;
	while (line[l])
	{
		if ((line[init] == '"' && line[l] == '"')
			|| (line[init] == '\'' && line[l] == '\''))
		{
			quote = ft_substr(&line[init], 0, (l - init) + 1);
			data->quote_chars = l;
			if (line[l + 1] != '\0' && line[l + 1] != ' ')
			{
				init = l + 1;
				quote = find_more_quotes(line, l, quote, data);
			}
			break ;
		}
		l++;
	}
	return (quote);
}

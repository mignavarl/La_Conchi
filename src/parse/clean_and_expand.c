/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 15:59:36 by mignavar          #+#    #+#             */
/*   Updated: 2025-02-11 15:59:36 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*single_quote(char *old_word, char *new_word, t_data *data)
{
	data->quote_chars++;
	while (old_word[data->quote_chars] != '\'')
	{
		new_word[data->new_quote] = old_word[data->quote_chars];
		data->new_quote++;
		data->quote_chars++;
	}
	data->quote_chars++;
	return (new_word);
}

char	*put_rest(char *old_word, char *new_word, t_env *env, t_data *data)
{
	while (old_word[data->quote_chars] && old_word[data->quote_chars] != '"' &&
			old_word[data->quote_chars] != '\'')
	{
		if (old_word[data->quote_chars] == '$')
		{
			new_word = expand_var_quote(old_word, new_word, env, data);
			data->new_quote = ft_strlen(new_word);
		}
		else
		{
			new_word[data->new_quote] = old_word[data->quote_chars];
			data->new_quote++;
			data->quote_chars++;
		}
	}
	return (new_word);
}

char	*clean_word(char *old_word, t_env *env, t_data *data)
{
	char	*new_word;

	data->quote_chars = 0;
	data->new_quote = 1;
	new_word = ft_calloc(ft_strlen(old_word) + 2, sizeof(char));
	new_word[0] = '"';
	while (old_word[data->quote_chars])
	{
		if (old_word[data->quote_chars] == '"')
			new_word = double_quote(old_word, new_word, env, data);
		else if (old_word[data->quote_chars] == '\'')
			new_word = single_quote(old_word, new_word, data);
		else
			new_word = put_rest(old_word, new_word, env, data);
	}
	free(old_word);
	new_word[data->new_quote] = '"';
	return (new_word);
}

char	**clean_and_expand(char **words, t_env *env, t_data *data)
{
	int	w;

	w = 0;
	while (words[w])
	{
		if (ft_have_this(words[w], '\'') || ft_have_this(words[w], '"')
			 || ft_have_this(words[w], '$'))
			words[w] = clean_word(words[w], env, data);
		w++;
	}
	return (words);
}

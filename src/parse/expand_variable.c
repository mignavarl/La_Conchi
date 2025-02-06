/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 15:00:07 by mignavar          #+#    #+#             */
/*   Updated: 2025-01-27 15:00:07 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_var_more(char *old_word, char *new_word, char *value)
{
	char	*var_word;
	int		new;
	int		old;

	var_word = ft_calloc((ft_strlen(old_word) + ft_strlen(new_word) + 
				ft_strlen(value) + 1), sizeof(char));
	old = 0;
	while (new_word[old])
	{
		var_word[old] = new_word[old];
		old++;
	}
	new = old;
	old = 0;
	while (value[old])
	{
		var_word[new] = value[old];
		new++;
		old++;
	}
	free(new_word);
	return (var_word);
}

char	*expand_var_quote(char *old_word, char *new_word, t_env *env, t_data *data)
{
	char	*key;
	char	*value;
	int		k;
	
	k = data->quote_chars + 1;
	while (old_word[k] && old_word[k] != '"' && old_word[k] != ' ' && old_word[k] != '\'')
		k++;
	key = ft_substr(old_word, data->quote_chars + 1, (k - data->quote_chars) - 1);
	if (!ft_strcmp(key, "?"))
		value = ft_itoa(data->last_exit);
	else
		value = get_env_var(env, key);
	data->quote_chars = k;
	if (!value)
		return (new_word);
	new_word = join_var_more(old_word, new_word, value);
	if (!ft_strcmp(key, "?"))
		free(value);
	free(key);
	return(new_word);
}

char	*double_quote(char *old_word, char *new_word, t_env *env, t_data *data)
{
	data->quote_chars++;
	while (old_word[data->quote_chars] && old_word[data->quote_chars] != '"')
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
	data->quote_chars++;
	return (new_word);
}

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

int		have_dollar(char *word)
{
	int	d;

	d = 0;
	while (word[d])
	{
		if (word[d] == '$')
			return (1);
		d++;
	}
	return (0);
}

char	**clean_and_expand(char **words, t_env *env, t_data *data)
{
	int	w;

	w = 0;
	while (words[w])
	{
		if (words[w][0] == '"' || words [w][0] == '\'' || have_dollar(words[w]))
			words[w] = clean_word(words[w], env, data);
		w++;
	}
	return (words);
}

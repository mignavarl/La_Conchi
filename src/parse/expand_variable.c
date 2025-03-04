/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:00:07 by mignavar          #+#    #+#             */
/*   Updated: 2025/03/04 14:48:48 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_var_more(char *old_word, char *new_word, char *value)
{
	char	*var_word;
	int		new;
	int		old;

	var_word = ft_calloc((ft_strlen(old_word) + ft_strlen(new_word)
				+ ft_strlen(value) + 1), sizeof(char));
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

char	*expand_var_quote(char *old, char *new, t_env *env, t_data *data)
{
	char	*key;
	char	*value;
	int		k;

	k = data->quote_chars + 1;
	while (old[k] && old[k] != '"' && old[k] != ' '
		&& old[k] != '\'' && old[k] != '$')
		k++;
	key = ft_substr(old, data->quote_chars + 1, (k - data->quote_chars) - 1);
	if (!ft_strcmp(key, "?"))
		value = ft_itoa(data->last_exit);
	else
		value = get_env_var(env, key);
	data->quote_chars = k;
	if (!value)
		return (free(key), new);
	new = join_var_more(old, new, value);
	if (!ft_strcmp(key, "?"))
		free(value);
	free(key);
	return (new);
}

char	*double_quote(char *old_word, char *new_word, t_env *env, t_data *data)
{
	data->quote_chars++;
	while (old_word[data->quote_chars] && old_word[data->quote_chars] != '"')
	{
		if (old_word[data->quote_chars] == '$'
			&& old_word[data->quote_chars + 1] != ' '
			&& old_word[data->quote_chars + 1] != '\0'
			&& old_word[data->quote_chars + 1] != '"')
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

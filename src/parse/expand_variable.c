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
	while (old_word[k] && old_word[k] != '"' && old_word[k] != ' '
			&& old_word[k] != '\'' && old_word[k] != '$')
		k++;
	key = ft_substr(old_word, data->quote_chars + 1, (k - data->quote_chars) - 1);
	if (!ft_strcmp(key, "?"))
		value = ft_itoa(data->last_exit);
	else
		value = get_env_var(env, key);
	data->quote_chars = k;
	if (!value)
	{
		free(key);
		return (new_word);
	}
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

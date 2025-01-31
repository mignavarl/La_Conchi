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

/* char	*expand_var_quote(char *old_word, char *new_word, t_env *env, t_data *data)
{
	char	
}

char	*double_quote(char *old_word, char *new_word, t_env *env, t_data *data)
{
	int	n;

	n = 0;
	data->quote_chars++;
	while (old_word[data->quote_chars] != '"')
	{
		if (old_word[data->quote_chars] == '$')
		{
			new_word = expand_var_quote(old_word, new_word, env, data);
		}
		new_word[n] = old_word[data->quote_chars];
		n++;
		data->quote_chars++;
	}
}

char	*clean_word(char *old_word, t_env *env, t_data *data)
{
	char	*new_word;

	data->quote_chars = 0;
	new_word = ft_calloc(ft_strlen(old_word), sizeof(char));
	while (old_word[data->quote_chars])
	{
		if (old_word[data->quote_chars] == '"')
			new_word = double_quote(old_word, new_word, env, data);
		else if (old_word[data->quote_chars] == '\'')
			new_word = single_quote(old_word, new_word, data);
		else
			new_word = put_rest(old_word, new_word, env, data);
	}
	return (new_word);
}

char	**clean_and_expand(char **words, t_env *env, t_data *data)
{
	int	w;

	w = 0;
	while (words[w])
	{
		if (words[w][0] == '"' || words [w][0] == '\'')
			words[w] = clean_word(words[w], env, data);
		w++;
	}
	return (words);
}
 */
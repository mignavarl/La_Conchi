/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-13 10:32:53 by mignavar          #+#    #+#             */
/*   Updated: 2025-02-13 10:32:53 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_word(char *word)
{
	int	init;

	init = 0;
	while (word[init])
	{
		if (!m_ischar(&word[init]))
		{
			return (init);
		}
		init++;
	}
	return (0);
}

int	word_len(char *word)
{
	int	len;

	len = 0;
	while (m_ischar(&word[len]) > 0)
		len++;
	len = 0;
	while (word[len])
		len++;
	while (m_ischar(&word[len - 1]) > 0)
		len--;
	return (len);
}

int	find_last_sym(char *word)
{
	int	l;

	l = ft_strlen(word) - 1;
	if (l < 0)
		return (0);
	while (l >= 0 && m_ischar(&word[l]))
		l--;
	return (l + 1);
}

char	*m_find_word(char *line)
{
	char	*word;
	int		init;
	int		end;

	init = 0;
	while (m_ischar(&line[init]) && line[init])
		init++;
	end = init;
	while (!m_ischar(&line[end]) && line[end])
	{
		end++;
		if (m_ischar(&line[end]))
			break ;
	}
	word = ft_substr(line, init, end);
	return (word);
}

int	next_word(char *word, int i)
{
	while (!m_ischar(&word[i]) && word[i])
		i++;
	while (m_ischar(&word[i]) && word[i])
		i--;
	return (i);
}

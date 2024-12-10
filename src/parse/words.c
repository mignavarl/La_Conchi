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

char *find_words(char *line, int i)
{
	int		l;
	char	*word;

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
	return (word);
}

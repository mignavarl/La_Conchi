/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:13:10 by mignavar          #+#    #+#             */
/*   Updated: 2024/01/30 10:53:32 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	l;
	int	word;

	l = 0;
	word = 0;
	while (s[l])
	{
		if (s[l] == c)
			l++;
		else if (s[l] != c && (s[l + 1] == c || s[l + 1] == '\0'))
		{
			l++;
			word++;
		}
		else
			l++;
	}
	return (word);
}

static int	len_word(char const *s, int l, char c)
{
	int	len;

	len = 0;
	while (s[l] != c && s[l])
	{
		len++;
		l++;
	}
	return (len);
}

static void	free_all(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
}

static char	**fill(char const *s, char c, char **str, int count)
{
	int	j;
	int	len;
	int	word;

	j = 0;
	len = 0;
	while (j < count && s[len] != '\0')
	{
		if (s[len] != c)
		{
			word = len_word(s, len, c);
			str[j] = ft_substr(s, len, word);
			if (!str[j])
			{
				free_all(str, j);
				return (NULL);
			}
			j++;
			len = len + (word - 1);
		}
		len++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**str;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	str = (char **)ft_calloc((count + 1), sizeof(char *));
	if (!str)
		return (NULL);
	if (count == 0)
		str[0] = NULL;
	str = fill((char *)s, c, str, count);
	return (str);
}

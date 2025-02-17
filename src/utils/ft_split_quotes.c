/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:34:39 by osredond          #+#    #+#             */
/*   Updated: 2025/02/17 16:58:39 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int detect_quote(char c)
{
    static int double_q;// --> T
    static int simple_q;

	if (c == '\"')
		double_q = !double_q;
	else if (c == '\'')
		simple_q = !simple_q;
}

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

/* static void	free_all(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
}
 */
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
				return (free_all(&str), NULL);
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

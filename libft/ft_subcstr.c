/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subcstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-30 10:21:21 by mignavar          #+#    #+#             */
/*   Updated: 2024-05-30 10:21:21 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_subcstr(char const *s, char c)
{
	char	*sub;
	int		i;
	int		f;

	i = 0;
	f = 0;
	if (!s)
		return (NULL);
	while (s[i] != c && s[i])
		i++;
	sub = (char *)malloc(i * sizeof(char));
	if (!sub)
		return (NULL);
	while (f < i)
	{
		sub[f] = s[f];
		f++;
	}
	sub[f] = '\0';
	return (sub);
}

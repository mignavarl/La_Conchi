/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:14:01 by mignavar          #+#    #+#             */
/*   Updated: 2023/09/26 15:58:14 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	s;
	size_t	f;

	s = 0;
	if (find[0] == '\0')
		return ((char *)str);
	while (str[s] != '\0' && s < len)
	{
		f = 0;
		while (str[s + f] == find[f] && find[f] != '\0' && (s + f) < len)
		{
			if (str[s + f] == find[f] && find[f + 1] == '\0')
				return ((char *)&str[s]);
			f++;
		}
		if (find[f] == '\0')
			return ((char *)&str[s]);
		s++;
	}
	return (0);
}

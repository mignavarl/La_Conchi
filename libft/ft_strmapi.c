/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:23:26 by mignavar          #+#    #+#             */
/*   Updated: 2023/10/03 11:01:32 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		l;
	char				*str;

	l = 0;
	str = ft_strdup(s);
	if (!s || !f || !str)
		return (NULL);
	while (str[l])
	{
		str[l] = f(l, str[l]);
		l++;
	}
	str[l] = '\0';
	return (str);
}

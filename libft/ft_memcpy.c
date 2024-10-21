/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:26:51 by mignavar          #+#    #+#             */
/*   Updated: 2023/10/02 16:33:38 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		l;
	char		*d;
	const char	*s;

	l = 0;
	d = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (0);
	while (l < n)
	{
		d[l] = s[l];
		l++;
	}
	return (dest);
}

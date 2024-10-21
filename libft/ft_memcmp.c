/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:14:35 by mignavar          #+#    #+#             */
/*   Updated: 2023/10/18 15:07:40 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		l;

	l = 0;
	if (n == 0)
		return (0);
	while (((unsigned char *)s1)[l] == ((unsigned char *)s2)[l] && l < n - 1)
	{
		l++;
	}
	return (((unsigned char *)s1)[l] - ((unsigned char *)s2)[l]);
}

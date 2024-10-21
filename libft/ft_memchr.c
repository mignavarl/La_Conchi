/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:58:34 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/02 12:12:56 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	l;

	l = 0;
	while (l < n && ((unsigned char *)str)[l] != (unsigned char)c)
		l++;
	if (n == l)
		return (NULL);
	return ((void *)str + l);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:12:49 by mignavar          #+#    #+#             */
/*   Updated: 2024/01/30 10:53:52 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstsize;
	size_t	totalsize;
	size_t	l;

	if ((!dst || !src) && size == 0)
		return (0);
	dstsize = ft_strlen(dst);
	totalsize = (ft_strlen(dst) + ft_strlen(src));
	l = 0;
	if (size <= dstsize)
		return (ft_strlen(src) + size);
	while (dstsize < (size - 1) && src[l] != '\0')
	{
		dst[dstsize] = src[l];
		dstsize++;
		l++;
	}
	dst[dstsize] = '\0';
	return (totalsize);
}

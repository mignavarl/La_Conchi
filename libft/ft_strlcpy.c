/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:40:26 by mignavar          #+#    #+#             */
/*   Updated: 2023/09/21 12:02:02 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	l;

	l = 0;
	srcsize = ft_strlen(src);
	if (dstsize != 0)
	{
		while (src[l] != '\0' && l < (dstsize - 1))
		{
			dst[l] = src[l];
			l++;
		}
		dst[l] = '\0';
	}
	return (srcsize);
}

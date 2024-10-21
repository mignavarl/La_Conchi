/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:36:09 by mignavar          #+#    #+#             */
/*   Updated: 2023/09/26 15:55:00 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	c;

	c = 0;
	if (n == 0)
		return (0);
	while (*s1 == *s2 && *s1 && *s2 && c < n - 1)
	{
		s1++;
		s2++;
		c++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

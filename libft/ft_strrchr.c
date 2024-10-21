/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:14:16 by mignavar          #+#    #+#             */
/*   Updated: 2023/09/19 18:58:25 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	l;

	ch = (char)ch;
	l = ft_strlen(str);
	while (l > 0 && str[l] != ch)
		l--;
	if (str[l] == ch)
		return ((char *)str + l);
	return (0);
}

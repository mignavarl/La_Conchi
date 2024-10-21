/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-19 15:28:17 by mignavar          #+#    #+#             */
/*   Updated: 2024-09-19 15:28:17 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_threejoin(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*str;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	str = ft_strjoin(tmp, s3);
	free(tmp);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

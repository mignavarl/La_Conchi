/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:28:17 by mignavar          #+#    #+#             */
/*   Updated: 2025/03/04 17:00:13 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_threejoin(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*str;

	if (!*s1 || !*s2 || !*s3)
		return (NULL);
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

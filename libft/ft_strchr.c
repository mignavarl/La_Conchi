/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:10:53 by mignavar          #+#    #+#             */
/*   Updated: 2023/10/26 16:39:26 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int ch)
{
	while (*str != '\0' && *str != (char)ch)
		str++;
	if (*str == (char)ch)
		return ((char *)str);
	return (0);
}

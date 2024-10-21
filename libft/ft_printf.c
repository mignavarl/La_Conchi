/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:21:20 by mignavar          #+#    #+#             */
/*   Updated: 2024/01/30 13:05:04 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pr_next(char c, va_list args, int p)
{
	if (c == 'c')
		p += pr_char(va_arg(args, int));
	else if (c == 'i' || c == 'd')
		p += pr_int(va_arg(args, int));
	else if (c == 'u')
		p += pr_unsign(va_arg(args, int));
	else if (c == 's')
		p += pr_str(va_arg(args, char *));
	else if (c == '%')
		p += pr_char('%');
	else if (c == 'x')
		p += pr_hex(va_arg(args, unsigned int));
	else if (c == 'X')
		p += pr_hex_m(va_arg(args, unsigned int));
	else if (c == 'p')
		p += pr_void(va_arg(args, size_t));
	else
		p += pr_char(c);
	return (p);
}

int	ft_printf(char const *str, ...)
{
	int		p;
	va_list	args;

	p = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			p = pr_next(*(str + 1), args, p);
			str++;
		}
		else
			p += pr_char(*str);
		str++;
	}
	va_end(args);
	return (p);
}

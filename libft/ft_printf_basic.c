/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:44:18 by mignavar          #+#    #+#             */
/*   Updated: 2024/01/30 13:03:50 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pr_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	pr_int(int n)
{
	int	p;

	p = 0;
	if (n == -2147483648)
	{
		write(1, "-2", 2);
		n = 147483648;
		p = 2;
	}
	if (n < 0)
	{
		pr_char('-');
		n *= -1;
		p = 1;
	}
	if (n < 10)
	{
		p += pr_char((n + 48));
		return (p);
	}
	else
		p += pr_int(n / 10);
	p += pr_char ((n % 10 + 48));
	return (p);
}

int	pr_unsign(int n)
{
	int		p;
	long	l;

	p = 0;
	if (n >= 0)
		p = pr_int(n);
	if (n < 0)
	{
		l = n + 4294967296;
		if (l < 10)
		{
			p += pr_char((l + 48));
			return (p);
		}
		else
			p += pr_int(l / 10);
		p += pr_char ((l % 10 + 48));
	}
	return (p);
}

int	pr_str(char *str)
{
	int	p;

	p = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[p] != '\0')
	{
		write(1, &str[p], 1);
		p++;
	}
	return (p);
}

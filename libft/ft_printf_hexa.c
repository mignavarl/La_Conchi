/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:52:25 by mignavar          #+#    #+#             */
/*   Updated: 2024/01/30 13:03:53 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pr_hex(size_t n)
{
	int		p;
	char	*base;

	p = 0;
	base = "0123456789abcdef";
	if (n < 16)
	{
		write(1, &base[n], 1);
		return (1);
	}
	else
		p += pr_hex(n / 16);
	write(1, &base[n % 16], 1);
	p++;
	return (p);
}

int	pr_hex_m(size_t n)
{
	int		p;
	char	*base;

	p = 0;
	base = "0123456789ABCDEF";
	if (n < 16)
	{
		write(1, &base[n], 1);
		return (1);
	}
	else
		p += pr_hex_m(n / 16);
	write(1, &base[n % 16], 1);
	p++;
	return (p);
}

int	pr_void(size_t n)
{
	int	p;

	p = 2;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	p += pr_hex(n);
	return (p);
}

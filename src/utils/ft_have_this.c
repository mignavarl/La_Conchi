/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_have_this.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-14 10:08:33 by mignavar          #+#    #+#             */
/*   Updated: 2025-02-14 10:08:33 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_have_this(char *word, int this)
{
	int	d;

	d = 0;
	while (word[d])
	{
		if (word[d] == this)
			return (1);
		d++;
	}
	return (0);
}

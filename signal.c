/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-04 08:36:58 by mignavar          #+#    #+#             */
/*   Updated: 2024-10-04 08:36:58 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prueba_mini.h"

void	trapper(int sig)
{
	if (sig == 2)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	find_signal(void)
{
	signal(SIGINT, trapper); 
	signal(SIGQUIT, SIG_IGN);
	// int	i;

	// i = 1;
	// while (1 <= 64)
	// {
	// 	signal(i, trapper);
	// 	i++;
	// }
}

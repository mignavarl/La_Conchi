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

#include "minishell.h"

void	trapper(int sig)
{
	if (sig == SIGINT)
	{
		ioctl(1, TIOCSTI, "\n");
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	find_signal(void)
{
	signal(SIGINT, trapper);
	signal(SIGQUIT, SIG_IGN);
}

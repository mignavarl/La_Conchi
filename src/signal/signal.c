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

void	trapper_inter(int sig)
{
	if (sig == 2)
	{
		printf("\n");
		// rl_on_new_line();
		// rl_replace_line("", 0);
		//rl_redisplay();
	}
}

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

void	find_signal(t_data *data)
{
	if (data->signal_switch == 0)
	{
		signal(SIGINT, trapper); 
		signal(SIGQUIT, SIG_IGN);
	}
	if (data->signal_switch == 1)
	{
		signal(SIGINT, trapper_inter); 
		signal(SIGQUIT, SIG_IGN);
	}
}

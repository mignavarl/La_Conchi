/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-08 15:27:32 by mignavar          #+#    #+#             */
/*   Updated: 2025-01-08 15:27:32 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	restaure_fd(t_data *data)
{
	dup2(data->clon_stdout, STDOUT_FILENO);
	close(data->clon_stdout);
}

void	save_fd(t_data *data)
{
	data->clon_stdin = dup(STDIN_FILENO);
	data->clon_stdout = dup(STDOUT_FILENO);
	data->delim_pipe = 0;
}

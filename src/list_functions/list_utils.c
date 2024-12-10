/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 10:31:41 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-10 10:31:41 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	m_listclear(t_cmds **lst, void (*del)(void *))
{
	t_cmds	*tmp;

	if (!lst)
	{
		del(lst);
		return ;
	}
	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = tmp -> next;
		if (tmp -> cmd)
			del(tmp -> cmd);
		free(tmp);
	}
	lst = NULL;
}

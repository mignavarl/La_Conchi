/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 10:30:37 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-10 10:30:37 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	m_lstsize(t_cmds *lst)
{
	t_cmds	*l;
	int		i;

	l = lst;
	i = 0;
	while (l != NULL)
	{
		i++;
		l = l -> next;
	}
	return (i);
}

t_cmds	*m_lst_intnew(char *com)
{
	t_cmds	*s;

	s = malloc(sizeof(t_cmds));
	if (!s)
		return (NULL);
	s -> cmd = com;
	s -> next = NULL;
	return (s);
}

void	m_lstadd_front(t_cmds **lst, t_cmds *cmd)
{
	cmd -> next = *lst;
	*lst = cmd;
}

t_cmds	*m_lstlast(t_cmds *lst)
{
	t_cmds	*l;

	l = lst;
	while (l != NULL)
	{
		if (l -> next == NULL)
			return (l);
		l = l -> next;
	}
	return (0);
}

void	m_lstadd_back(t_cmds **lst, t_cmds *cmd)
{
	t_cmds	*l;

	if (!cmd)
		return ;
	if (!*lst)
	{
		*lst = cmd;
		return ;
	}
	l = m_lstlast(*lst);
	l->next = cmd;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:30:37 by mignavar          #+#    #+#             */
/*   Updated: 2025/03/04 16:57:31 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	cmd->quote = 0;
	l->next = cmd;
}

void	m_lstadd_back_quote(t_cmds **lst, t_cmds *cmd, int quote)
{
	t_cmds	*l;

	if (!cmd)
		return ;
	if (quote == '"')
		cmd->quote = 1;
	else if (quote == '\'')
		cmd->quote = 2;
	else
		cmd->quote = 0;
	if (!*lst)
	{
		*lst = cmd;
		return ;
	}
	l = m_lstlast(*lst);
	l->next = cmd;
}

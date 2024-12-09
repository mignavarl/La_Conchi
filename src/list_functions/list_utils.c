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

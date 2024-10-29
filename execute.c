#include "prueba_mini.h"

void	loop_cmd(t_cmds *now, t_cmds *next)
{
	if (!m_ischar(next->next, NULL))
		next = next->next;
	
}

void	execute(t_data	*data, t_cmds **cmd)
{
	t_cmds	*now;
	t_cmds	*next;
	int		size;
	int		i;

	now = cmd;
	size = m_lstsize(cmd);
	if (size > 1)
		next = now->next;
	else
	{
		execute_cmds(now);
		return ;
	}
	i = 0;
	while (i < size)
	{
		loop_cmd(now, next);
		now = next->next;
		next = now->next;
		i++;
	}
}

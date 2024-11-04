#include "prueba_mini.h"

void loop_cmd(t_cmds *now, t_cmds *next)
{
	char	*command;

	while (now || now->next != NULL)
	{
		command = ft_strdup(now->cmd);
		while (!m_ischar(next->cmd, NULL) || next->next != NULL)
		{
			command = ft_threejoin(command, " ", next->cmd); 
			next = next->next;
		}
		if (!ft_strcmp(next->cmd, "|"))
			make_pipe(command);
		if (!ft_strcmp(next->cmd, "<"))
			make_input();
		now = next->next;
	}
	waitpid(-1, NULL, 0);
}

void	execute(t_cmds **cmd)
{
	t_cmds	*now;
	t_cmds	*next;

	now = *cmd;
	if (m_lstsize(*cmd) > 1)
		next = now->next;
	else
	{
		execute_cmds(now);
		return ;
	}
	loop_cmd(now, next);
}

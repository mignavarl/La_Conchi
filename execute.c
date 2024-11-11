#include "prueba_mini.h"

void loop_cmd(t_cmds *now, t_cmds *next, t_env *env)
{
	char	*command;

	while (now)
	{
		command = ft_strdup(now->cmd);
		while (next && next->cmd && !m_ischar(next->cmd))
		{
			command = ft_threejoin(command, " ", next->cmd); 
			next = next->next;
		}
		if (next && m_ischar(next->cmd))
		{
			// if (!ft_strcmp(next->cmd, "|"))
			// 	make_pipe(ft_split(command, ' '), env);
			// if (!ft_strcmp(next->cmd, "<"))
			// 	make_input();
		}
		else
		{
			execute_cmd(ft_split(command, ' '), env);
			break ;
		}
		now = next->next;
	}
	waitpid(-1, NULL, 0);
}

void	execute(t_cmds **cmd, t_env *env)
{
	t_cmds	*now;
	t_cmds	*next;

	now = *cmd;
	if (m_lstsize(*cmd) > 1)
	{
		next = now->next;
		loop_cmd(now, next, env);
	}
	else
	{
		execute_cmd(ft_split(now->cmd, ' '), env);
		return ;
	}
}

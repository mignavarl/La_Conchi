#include "prueba_mini.h"

void loop_cmd(t_cmds *now, t_cmds *next, t_env *env)
{
	char	**command;
	int		i;

	i = 0;
	command = malloc(sizeof(char *));
	while (now)
	{
		while (next && next->cmd && !m_ischar(next->cmd))
		{
			command[i] = ft_strdup(next->cmd);
			next = next->next;
			i++;
		}
		command[i] = NULL;
		if (next && m_ischar(next->cmd))
		{
			// if (!ft_strcmp(next->cmd, "|"))
			// 	make_pipe(command, env);
			// if (!ft_strcmp(next->cmd, "<"))
			// 	make_input(command, env);
		}
		else
		{
			execute_cmd(command, env);
			printf("execute\n");
			break ;
		}
		now = next->next;
	}
	printf("wait\n");
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

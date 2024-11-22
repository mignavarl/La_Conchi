#include "prueba_mini.h"

void	save_fd(t_data *data)
{
	data->clon_stdin = dup(STDIN_FILENO);
	data->clon_stdout = dup(STDOUT_FILENO);
}

int	count_com(t_cmds *now)
{
	t_cmds *tmp;
	int		i;
	
	tmp = now;
	i = 0;
	while(tmp && tmp->cmd && !m_ischar(tmp->cmd))
	{
		tmp = tmp->next;
		i++;
	}
	return (i + 1);
}

void	loop_cmd(t_cmds *now, t_cmds *next, t_env *env, t_data *data)
{
	char	**command;
	int		i;

	save_fd(data);
	while (now)
	{
		i = 1;
		command = malloc(count_com(now) * sizeof(char *));//TODO: función saber cuantos hay
		command[0] = ft_strdup(now->cmd);
		while (next && next->cmd && !m_ischar(next->cmd))
		{
			command[i] = ft_strdup(next->cmd);
			//printf("[%d] = %s\n", i, next->cmd);
			next = next->next;
			i++;
		}
		command[i] = NULL;
		if (next && m_ischar(next->cmd))
		{
			data->to_close = 1;
			if (!ft_strcmp(next->cmd, "|"))
				make_pipe(command, env, data);
			if (!ft_strcmp(next->cmd, "<"))
			{
				next = next->next;
				make_input(command, env, next->cmd);
				if (!next->next)
					break ;
			}
			// if (!ft_strcmp(next->cmd, ">"))
			// {
				
			// }
		}
		else
		{
			execute_cmd(command, env);
			break ;
		}
		now = next->next;
		next = now->next;
	}
}

void	execute(t_cmds **cmd, t_env *env, t_data *data)
{
	t_cmds	*now;
	t_cmds	*next;

	now = *cmd;
	if (m_lstsize(*cmd) > 1)
	{	
		next = now->next;
		loop_cmd(now, next, env, data);
	}
	else
	{
		execute_cmd(ft_split(now->cmd, ' '), env);
		return ;
	}
}

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

void	restaure_fd(t_data *data)
{
	dup2(data->clon_stdout, STDOUT_FILENO);
	close(data->clon_stdout);
}

void loop_cmd(t_cmds *now, t_cmds *next, t_env *env, t_data *data)
{
    char    **command;
    int     i;

    save_fd(data);
	i = 0;
    while (now)
    {
		if (i == 0 && !ft_strcmp(now->cmd, ">"))
		{
			data->to_close = 1;
			first_argument_output(next->cmd);
			if (next->next)
			{
				restaure_fd(data);
				now = next->next;
				if (m_ischar(now->cmd))
					now = now->next;
				if (now->next)
					next = now->next;
				else
					next = NULL;
			}
			else
				break ;
		}
        i = 1;
        command = ft_calloc(count_com(now), sizeof(char *));  // Asignación de memoria para el array de comandos
        if (!command)
            return; // Si malloc falla, salimos de la función
        command[0] = ft_strdup(now->cmd);  // Copia del comando
        if (!command[0])  // Verifica si la asignación falla
        {
            free(command);  // Liberar el array de comandos en caso de error
            return;
        }
        while (next && next->cmd && !m_ischar(next->cmd))
        {
            command[i] = ft_strdup(next->cmd);  // Copia de los comandos siguientes
            if (!command[i])  // Verifica si la asignación falla
            {
                ft_free_double(command);  // Liberar el array de comandos si algo falla
                return;
            }
            next = next->next;
            i++;
        }
        command[i] = NULL;  // Terminamos el array de comandos
        if (next && m_ischar(next->cmd))
        {
            data->to_close = 1;
            if (!ft_strcmp(next->cmd, "|"))
                make_pipe(command, env, data);
            if (!ft_strcmp(next->cmd, "<"))
            {
				//printf("Input:\n%s\n", next->cmd);
                next = next->next;
				//printf("%s\n", next->cmd);
                make_input(command, env, next->cmd);
                if (!next->next)
				{
					ft_free_double(command);
                    break ;
				}
            }
			if (!ft_strcmp(next->cmd, ">"))
			{
				next = next->next;
				make_output(command, env, next->cmd);
				if (!next->next)
				{
					ft_free_double(command);
					break ;
				}
			}
        }
        else
        {
            execute_cmd(command, env);  // Ejecutar el comando
			break ;
        }
     //   ft_free_double(command);  // Liberar el array de comandos después de usarlo
        // now = next->next;
        // next = now->next;
		if(next->next)
        	now = next->next; //Protección añadida, (solo accede al siguiente valor de la lista, si es que esta contiene algo nwn)
		else
			now = NULL;
		if (now->next)
        	next = now->next; //Protección añadida, (solo accede al siguiente valor de la lista, si es que esta contiene algo nwn)
		else
			next = NULL;
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

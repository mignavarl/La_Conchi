/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 10:31:33 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-10 10:31:33 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_com(t_cmds *now)
{
	t_cmds *tmp;
	int		i;
	
	tmp = now;
	i = 0;
	if (!ft_strcmp(tmp->cmd, "<<"))
	{
		tmp = tmp->next;
		i++;
		while(tmp && tmp->cmd && !m_ischar(tmp->cmd))
		{
			tmp = tmp->next;
			i++;
		}
	}
	else
	{
		while(tmp && tmp->cmd && !m_ischar(tmp->cmd))
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (i + 1);
}

void loop_cmd(t_cmds *now, t_cmds *next, t_env *env, t_data *data)
{
	char    **command;
	int     i;

	save_fd(data);
	i = 0;
	//TODO: meter función con los i = 0, que son los del principio. Asi ahorramos el i
	replace_here_doc(now);
	while (now)
	{
		if (i == 0 && !ft_strcmp(now->cmd, ">"))
		{
			data->to_close = 1;
			next = first_argument_output(next);
			if (next->next)
			{
				now = next->next;
				if (m_ischar(now->cmd))
				{
					restaure_fd(data);
					now = now->next;
				}
				if (now->next)
					next = now->next;
				else
					next = NULL;
			}
			else
				break ;
		}
		if (i == 0 && !ft_strcmp(now->cmd, "<"))
		{
			data->to_close = 1;
			if (!first_argument_input(next->cmd))
				break ;
			if (next->next)
			{
				now = next->next;
				if (m_ischar(now->cmd))
				{
					restaure_fd(data);
					now = now->next;
				}
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
			return ; // Si malloc falla, salimos de la función
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
		if (!ft_strcmp(now->cmd, "<<"))
		{
			data->to_close = 1;
			command = first_delimiter(command);
			if (!command)
				break ;
		}
		if (next && m_ischar(next->cmd))
		{
			data->to_close = 1;
			if (!ft_strcmp(next->cmd, "|"))
				make_pipe(command, env, data);
			if (!ft_strcmp(next->cmd, ">>"))
			{
				next = next->next;
				make_append(command, env, next->cmd);
				if (!next->next)
				{
					ft_free_double(command);
					break ;
				}
			}
			if (!ft_strcmp(next->cmd, "<<"))
			{
				next = next->next;
				next = make_delimiter(command, env, next->cmd, next);
				if (!next->next)
				{
					ft_free_double(command);
					break ;
				}
			}
			if (!ft_strcmp(next->cmd, "<"))
			{
				next = next->next;
				next = make_input(command, env, next->cmd, next);
				if (!next->next)
				{
					ft_free_double(command);
					break ;
				}
			}
			if (!ft_strcmp(next->cmd, ">"))
			{
				next = last_file_output(next->next);
				make_output(command, env, next->cmd);
				if (!next->next)
				{
					ft_free_double(command);
					break ;
				}
				data->to_close = 1;
			}
		}
		else
		{
			execute_cmd(command, env, 1);  // Ejecutar el comando
			break ;
		}
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
		if (m_ischar(now->cmd))
		{
			printf("La Conchi says: syntax error near %s\n", now->cmd);
			return ;
		}
		execute_cmd(ft_split(now->cmd, ' '), env, 1);
		return ;
	}
}

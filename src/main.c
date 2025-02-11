/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:23:30 by osredond          #+#    #+#             */
/*   Updated: 2024/11/23 21:48:36 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_cmd(t_cmds **comand)//TODO: BORRAR
{
	int i;
	t_cmds *tmp;

	i = 0;
	tmp = *comand;
	printf(CYAN"Print\n"END);
	while (tmp != NULL)
	{
		printf(CYAN"CMD (%d) = %s\n"END, i, tmp->cmd);
		if (tmp->next == NULL)
			break;
		i++;
		tmp = tmp->next;
	}
	printf(CYAN"FIN Print\n"END);
	printf("------------------------------------\n");
}

int	g_signal_c = 0;

int main(int argc, char **argv, char *envp[])
{
	(void)argv;
	t_data	data;
	t_cmds	*command;
	t_env	*env;
	char	*line;

	if (argc != 1)
	{
		printf(RED"Don't put arguments\n"END);
		return (0);
	}
	ft_memset(&data, 0, sizeof(t_data));
	env = NULL;
	env = init_env(envp, env);
	g_signal_c = 0;
	while (1)
	{
		find_signal();
		line = readline(GREEN"🐚La Conchi" YELLOW " ⇒ " END);
		if (!line || !ft_strcmp(line, "exit"))
		{
			ft_putendl_fd("exit", 2);
			free(line);
			free_env(env);
			break ;
		}
		add_history(line);
		data.words = search_in_line(line, &data, env); 
		if (!data.words)
			;
		else if (data.words[0])
		{
			command = NULL;
			command = list_cmd(command, data.words);
			print_cmd(&command);//TODO:PARA IMPRIMIR
			execute(&command, env, &data);
			close_pipe(data.pipe_fd, &data);
			while (waitpid(-1, NULL, 0) != -1)
				continue ;
			m_listclear(&command, free);
			g_signal_c = data.last_exit;
		}
		if (data.words)
			ft_free_double(&data.words);
		free(line);
	}
	return 0;
}

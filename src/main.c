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

	i = 0;
	printf(CYAN"Print\n"END);
	while ((*comand) != NULL)
	{
		printf(CYAN"CMD (%d) = %s\n"END, i, (*comand)->cmd);
		if ((*comand)->next == NULL)
			break;
		i++;
		(*comand) = (*comand)->next;
	}
}

int main(int argc, char **argv, char *envp[])
{
	(void)argc;
	(void)argv;
	t_data	data;
	t_cmds	*command;
	t_env	*env;
	char	*line;

	ft_memset(&data, 0, sizeof(t_data));
	while (1)
	{
		env = NULL;
		env = init_env(envp, env);
		find_signal();
		line = readline(GREEN"🐚La Conchi" YELLOW " ⇒ " END);
		if (!line || !ft_strcmp(line, "exit"))
		{
			printf("exit\n");
			free(line);
			free_env(env);
			break ;
		}
		add_history(line);
		data.words = search_in_line(line, &data);
		if (!data.words)
			;
		else if (data.words[0])
		{
			//Buscar en words
			// if (!check_chars(data.words, &chars))
			// {
			// 	printf(RED"A\n"END); 
			// }
			command = NULL;
			command = list_cmd(command, data.words);
			// print_cmd(&command);//PARA IMPRIMIR
			//printf("cmd = %p\n", command);
			execute(&command, env, &data);
			while (waitpid(-1, NULL, 0) != -1)
				continue ;
			m_listclear(&command, free);
		}
		free_env(env);
		free(line);
		ft_free_double(data.words);
		close_pipe(data.pipe_fd, &data);
	}
	return 0;
}

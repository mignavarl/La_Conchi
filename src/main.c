/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:23:30 by osredond          #+#    #+#             */
/*   Updated: 2025/02/17 19:52:59 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_signal_c = 0;

void	to_execute(t_cmds *command, t_data *data, t_env *env)
{
	int	status;

	status = 0;
	command = list_cmd(command, data->words, data);
	execute(&command, env, data);
	close_pipe(data->pipe_fd, data);
	while (waitpid(-1, &status, 0) != -1)
		continue ;
	m_listclear(&command, free);
	if (WIFSIGNALED(status))
		data->last_exit = 128 + WTERMSIG(status);
	else
		data->last_exit = WEXITSTATUS(status);
}

void	while_main(t_env *env, t_data *data)
{
	char	*line;
	t_cmds	*command;

	command = NULL;
	while (1)
	{
		g_signal_c = 0;
		find_signal();
		line = readline(GREEN"🐚La Conchi" YELLOW " ⇒ " END);
		if (!line || !ft_strcmp(line, "exit"))
			exit_mini(line, env);
		add_history(line);
		if (lexer(line))
			continue ;
		data->words = search_in_line(line, data, env);
		if (!data->words)
			;
		else if (data->words[0])
			to_execute(command, data, env);
		if (data->words)
			ft_free_double(&data->words);
		free(line);
	}
}

int	main(int argc, char **argv, char *envp[])
{
	t_data	data;
	t_env	*env;

	(void)argv;
	if (argc != 1)
	{
		printf(RED"Don't put arguments\n"END);
		return (0);
	}
	ft_memset(&data, 0, sizeof(t_data));
	env = NULL;
	env = init_env(envp, env);
	while_main(env, &data);
	clear_history();
	return (0);
}

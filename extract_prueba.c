#include "prueba_mini.h"

char	**search_in_line(char *line)
{
	int		i;
	int		w;
	int		num_words;
	char	**words;

	i = 0;
	num_words = count_words(line);
	if (num_words < 0)
	{
		printf(RED"Close the quotes\n"END);
		//search_end_while(line);
		return (NULL);
	}
	words = (char **)ft_calloc(num_words + 1, sizeof(char *));
	w = 0;
	if (line[0] == '\0')
	{
		words[0] = '\0';
		return(words);
	}
	while (line && line[i])
	{
		if (line[i] != '"' && line[i] != '\'' && line[i] != ' ')
		{
			words[w] = find_words(line, i);
			if (!words[w])
				break ;
			i += ft_strlen(words[w]) - 1;
			w++;
		}
		else if (line[i] == '"' || line[i] == '\'')
		{
			words[w] = find_quote(line, i);
			if (!words[w])
				break ;
			i += ft_strlen(words[w]);
			if (line[i] != ' ' || line[i] != '"' || line[i] != '\'')
				i++;
			w++;
		}
		i++;
	}
	// w = 0;
	// while (w < num_words)
	// {
	// 	printf("Word [%d] = %s / %d\n", w, words[w], w);
	// 	w++;
	// }
	return (words);
}

void	print_cmd(t_cmds **comand)
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

void	m_listclear(t_cmds **lst, void (*del)(void *))
{
	t_cmds	*tmp;

	if (!lst)
	{
		del(lst);
		return ;
	}
	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = tmp -> next;
		del(tmp -> cmd);
		free(tmp);
	}
	lst = NULL;
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
		data.words = search_in_line(line);
		if (!data.words)
		{
			printf("NADA\n");
		}
		if (data.words[0])
		{
			add_history(line);
			//Buscar en words
			// if (!check_chars(data.words, &chars))
			// {
			// 	printf(RED"A\n"END); 
			// }
			command = NULL;
			command = list_cmd(command, data.words);
			//print_cmd(&command);//PARA IMPRIMIR
			//printf("cmd = %p\n", command);
			execute(&command, env, &data);
			while (waitpid(-1, NULL, 0) != -1)
				continue ;
		}
		// }
		//RESET
		free(line);
		ft_free_double(data.words);
		free_env(env);
		m_listclear(&command, free);
		close_pipe(data.pipe_fd, &data);
	}
	return 0;
}

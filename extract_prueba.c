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
	while (line[i])
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
	w = 0;
	while (w < num_words)
	{
		printf("Word [%d] = %s / %d\n", w, words[w], w);
		w++;
	}
	return (words);
}

void	print_cmd(t_cmds *comand)
{
	int i;

	i = 0;
	printf("Print\n");
	while (comand != NULL)
	{
		printf(CYAN"CMD (%d) = %s\n"END, i, comand->cmd);
		if (comand->next == NULL)
			break;
		i++;
		comand = comand->next;
	}
}

void	m_listclear(t_cmds **lst, void (*del)(void *))
{
	t_cmds	*l;

	while (*lst != NULL)
	{
		l = *lst;
		*lst = l -> next;
		del(l -> cmd);
		free(l);
	}
}

int main(void)
{
	t_chars	chars;
	t_data	data;
	t_cmds	*command;
	char	*line;

	ft_memset(&chars, 0, sizeof(t_chars));
	ft_memset(&data, 0, sizeof(t_data));
	ft_memset(&command, 0, sizeof(t_cmds));
	while (1)
	{
		find_signal();
		line = readline(GREEN"🐚La Conchi" YELLOW " ⇒ " END);
		if (!line || !ft_strcmp(line, "exit"))
		{
			printf("exit\n");
			free(line);
			break ;
		}
		data.words = search_in_line(line);
		if (!data.words)
		{
			printf("NADA\n");
		}
		else
		{
			add_history(line);
			//ft_free_double(data.words);
		}
		//Buscar en words
		// if (!check_chars(data.words, &chars))
		// {
		// 	printf(RED"A\n"END); 
		// }
		//TODO: Separar en comandos y enlistar
		command = NULL;
		command = list_cmd(command, data.words);
		print_cmd(command);
		// //Ejecutar cosas
		// else
		// {
		// 	execute_cmds(data.words, count_words(line));
		// }
		//RESET
		// add_history(line);
		ft_memset(&chars, 0, sizeof(t_chars));
		// if (data.words)
		ft_free_double(data.words);
		m_listclear(&command, free);
		free(line);
	}
	return 0;
}

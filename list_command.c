#include "prueba_mini.h"

t_cmds	*m_lst_intnew(char *com)
{
	t_cmds	*s;

	s = malloc(sizeof(t_cmds));
	if (!s)
		return (NULL);
	s -> cmd = com;
	s -> next = NULL;
	return (s);
}

void	m_lstadd_front(t_cmds **lst, t_cmds *cmd)
{
	cmd -> next = *lst;
	*lst = cmd;
}

t_cmds	*m_lstlast(t_cmds *lst)
{
	t_cmds	*l;

	l = lst;
	while (l != NULL)
	{
		if (l -> next == NULL)
			return (l);
		l = l -> next;
	}
	return (0);
}

void	m_lstadd_back(t_cmds **lst, t_cmds *cmd)
{
	t_cmds	*l;

	if (!cmd)
		return ;
	if (!*lst)
	{
		*lst = cmd;
		return ;
	}
	l = m_lstlast(*lst);
	l->next = cmd;
}

int	init_word(char *word)
{
	int	init;

	init = 0;
	while (word[init])
	{
		if (!m_ischar(&word[init], NULL))
		{
			printf(BLUE"Init word = %d\n"END, init);
			return (init);
		}
		init++;
	}
	printf(BLUE"Init word = %d\n"END, init);
	return (0);
}

int	word_len(char *word)
{
	int	len;

	len = 0;
	while (m_ischar(&word[len], NULL) > 0)
			len++;
	len = 0;
	while (word[len])
	{
		len++;
	}
	while (m_ischar(&word[len - 1], NULL) > 0)
		len--;
	printf(BLUE"Word len = %d\n"END, len);
	return (len);
}

int	find_last_sym(char * word)
{
	int	l;

	l = ft_strlen(word);
	while (m_ischar(&word[l], NULL))
		l--;
	return (l - 1);
}

char	*m_find_word(char *line)
{
	char	*word;
	int		init;
	int		end;

	init = 0;
	while (m_ischar(&line[init], NULL) && line[init])
		init++;
	end = init;
	while (!m_ischar(&line[end], NULL) && line[end])
		end++;
	word = ft_substr(line, init, end);
	return (word);
}

int	next_word(char *word, int i)
{
	printf("Next word: %s\n", word);
	while (!m_ischar(&word[i], NULL) && word[i])
		i++;
	while (m_ischar(&word[i], NULL) && word[i])
		i++;
	return (i - 1);
}

t_cmds	*list_cmd(t_cmds *command, char **words)
{
	int	w;
	int	i;
	int	sym;
	int	com;

	w = 0;
	while (words[w])
	{
		i = 0;
		while (words[w][i])
		{
			//Mirar chars y si es el ultimo ponerselo al siguiente
			sym = m_ischar(&words[w][i], command);
			if (sym == 0)
			{
				printf(RED"4 Word[%d][i = %d - com = %d] = %s\n"END, w, i, com, &words[w][i]);
				m_lstadd_back(&command, m_lst_intnew(m_find_word(&words[w][i])));
				printf("i = %d\n", i);
				i = next_word(words[w], i);
				printf("i = %d\n", i);
				if (words[w][i + 1] == '\0')
					break ;
				sym = m_ischar(&words[w][i], NULL);
			}
			else if ((sym == 1 && words[w][i + 1] != '\0') ||
				(sym == 2 && words[w][i + 2] != '\0'))
			{
				com = sym + i;
				while (words[w][com])
				{
					if (m_ischar(&words[w][com], command) || words[w][com + 1] == '\0')
					{
						printf(RED"1 Word[%d][i = %d - com = %d] = %s\n"END, w, i, com, &words[w][i]);
						m_lstadd_back(&command, m_lst_intnew(ft_substr(words[w], i, com - i - 1)));
						break ;
					}
					com++;
				}
				sym = m_ischar(&words[w][com], command);
				printf("i = %d -- sym = %d -- com = %d\n", i, sym, com);
				i = com - 1;
			}
			else if ((sym == 1 && words[w][i + 1] == '\0') ||
				(sym == 2 && words[w][i + 2] == '\0'))
			{
				com = 0;
				if (!words[w + 1] || !m_ischar(words[w + 1], command))
				{
					printf(RED"2 Word[%d][i = %d - com = %d] = %s\n"END, w, i, com, &words[w][i]);
					m_lstadd_back(&command, m_lst_intnew(ft_substr (words[w], find_last_sym(words[w]), sym)));
					break ;
				}
				w++;
				while (words[w][com])
				{
					if (m_ischar(&words[w][com], command) || words[w][com + 1] == '\0')
					{
						printf(RED"3 Word[%d][i = %d - com = %d] = %s\n"END, w, i, com, &words[w][i]);
						m_lstadd_back(&command, m_lst_intnew(ft_substr(words[w], i, com - i)));
						break ;
					}
					com++;
				}
			}
			i++;
		}
		w++;
	}
	return (command);
}

/*TODO: 
		ls OK
		|ls KO: 0 = |
				1 = s (se come la l)
		ls| KO: 0 = ls (se come |)
		ls|d KO: 0 = ls
				 1 = d  (se come |)
*/
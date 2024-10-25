#include "prueba_mini.h"

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
	while (!m_ischar(&word[i], NULL) && word[i])
		i++;
	while (m_ischar(&word[i], NULL) && word[i])
		i--;
	printf("Next word: %s -- i = %d\n", word, i);
	return (i);
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
			if (sym == 0)//NO ES CHAR
			{
				printf(RED"4 Word[%d][i = %d - com = %d] = %s\n"END, w, i, com, &words[w][i]);
				m_lstadd_back(&command, m_lst_intnew(m_find_word(&words[w][i])));
				printf("i = %d\n", i);
				i = next_word(words[w], i);
				if (words[w][i] == '\0')
					i -= 1;
				printf("i = %d\n", i);
				if (words[w][i + 1] == '\0')
					break ;
				sym = m_ischar(&words[w][i], NULL) - 1;
			}
			else if ((sym == 1 && words[w][i + 1] != '\0') ||
				(sym == 2 && words[w][i + 2] != '\0'))//ES CHAR, NO EL ÚLTIMO
			{
				com = sym + i;
				while (words[w][com])
				{
					if (m_ischar(&words[w][com], command) || words[w][com + 1] == '\0')
					{
						printf(RED"1 Word[%d][i = %d - com = %d] = %s\n"END, w, i, com, &words[w][i]);
						if ((com - i - 1) == 0)
							m_lstadd_back(&command, m_lst_intnew(ft_substr(words[w], i, 1)));
						else
							m_lstadd_back(&command, m_lst_intnew(ft_substr(words[w], i, com - i - 1)));
						break ;
					}
					com++;
				}
				printf("i = %d -- sym = %d -- com = %d\n", i, sym, com);
				// if (words[w][com + 1] == '\0')
				// 	i = com - 2;
				// else
				// 	i = com + sym - 1;
				i = com;
				while (!m_ischar(&words[w][i], NULL))
					i--;
				sym = m_ischar(&words[w][com], command);
				printf("i = %d -- sym = %d -- com = %d\n", i, sym, com);
			}
			else if ((sym == 1 && words[w][i + 1] == '\0') ||
				(sym == 2 && words[w][i + 2] == '\0'))// ES CHAR Y SÍ EL ÚLTIMO
			{
				com = 0;
				if (!words[w + 1] || !m_ischar(words[w + 1], command))//HABRÍA QUE MIRAR ANTES QUE NO ACABE EN CHAR
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
		|ls OK: 0 = |
				1 = ls
		ls| OK: 0 = ls
				1 = |
		ls|d KO: Bucle infinito: queda |d
*/
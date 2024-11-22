#include "prueba_mini.h"

int	init_word(char *word)
{
	int	init;

	init = 0;
	while (word[init])
	{
		if (!m_ischar(&word[init]))
		{
			//printf(BLUE"Init word = %d\n"END, init);
			return (init);
		}
		init++;
	}
	//printf(BLUE"Init word = %d\n"END, init);
	return (0);
}

int	word_len(char *word)
{
	int	len;

	len = 0;
	while (m_ischar(&word[len]) > 0)
			len++;
	len = 0;
	while (word[len])
	{
		len++;
	}
	while (m_ischar(&word[len - 1]) > 0)
		len--;
	//printf(BLUE"Word len = %d\n"END, len);
	return (len);
}

int	find_last_sym(char *word)
{
	int	l;

	l = ft_strlen(word) - 1;
	//printf("Word = %s\nLen = %d\n", word, l);
	//printf("Char = %c", word[l]);
	while (m_ischar(&word[l]) && word[l])
	{
		//printf(YELLOW"Char = %c\n"END, word[l]);
		l--;
	}
	if (word[l] == '\0')
		return (ft_strlen(word) - 1);
	//printf("Last_sym = %d\n", (l - 1));
	return (l + 1);
}

char	*m_find_word(char *line)
{
	char	*word;
	int		init;
	int		end;

	init = 0;
	while (m_ischar(&line[init]) && line[init])
		init++;
	end = init;
	while (!m_ischar(&line[end]) && line[end])
	{
		end++;
		if (m_ischar(&line[end]))
			break ;
	}
	//printf("Find_word: Line = %s -- init = %d -- end = %d\n", line, init, end);
	word = ft_substr(line, init, end);
	return (word);
}

int	next_word(char *word, int i)
{
	while (!m_ischar(&word[i]) && word[i])
		i++;
	while (m_ischar(&word[i]) && word[i])
		i--;
	//printf("Next word: %s -- i = %d\n", word, i);
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
			if (i == 0 && (words[w][i] == '"' || words[w][i] == '\''))
			{
				m_lstadd_back(&command, m_lst_intnew(ft_substr(words[w], 1, (ft_strlen(words[w]) - 2))));
				break ;
			}
			sym = m_ischar(&words[w][i]);
			if (sym == 0)//NO ES CHAR
			{
				//printf(RED"4 Word[%d][i = %d - com = %d] = %s\n"END, w, i, com, &words[w][i]);
				m_lstadd_back(&command, m_lst_intnew(m_find_word(&words[w][i])));
				//printf("i = %d\n", i);
				i = next_word(words[w], i);
				if (words[w][i] == '\0')
					i -= 1;
				//printf("i = %d\n", i);
				if (words[w][i + 1] == '\0')
					break ;
				sym = m_ischar(&words[w][i]) - 1;
			}
			else if ((sym == 1 && words[w][i + 1] != '\0') ||
				(sym == 2 && words[w][i + 2] != '\0'))//ES CHAR, NO EL ÚLTIMO
			{
				com = sym + i;
				while (words[w][com])
				{
					if (m_ischar(&words[w][com]) || words[w][com + 1] == '\0')
					{
						//printf(RED"1 Word[%d][i = %d - com = %d] = %s\n"END, w, i, com, &words[w][i]);
						m_lstadd_back(&command, m_lst_intnew(ft_substr(words[w], i, sym)));
						break ;
					}
					com++;
				}
				//printf("i = %d -- sym = %d -- com = %d\n", i, sym, com);
				i = com - 1;
				while (!m_ischar(&words[w][i]))
					i--;
				sym = m_ischar(&words[w][com]);
				//printf("i = %d -- sym = %d -- com = %d\n", i, sym, com);
			}
			else if ((sym == 1 && words[w][i + 1] == '\0') ||
				(sym == 2 && words[w][i + 2] == '\0'))// ES CHAR Y SÍ EL ÚLTIMO
			{
				//printf(RED"2 Word[%d][i = %d - com = %d] = %s sym = %d\n"END, w, i, com, &words[w][i], sym);
				m_lstadd_back(&command, m_lst_intnew(ft_substr (words[w], find_last_sym(words[w]), sym)));
			}
			i++;
		}
		w++;
	}
	return (command);
}

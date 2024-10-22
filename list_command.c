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
		if (!m_ischar(&word[init], NULL) && m_ischar(&word[init - 1], NULL));
			return (init);
		init++;
	}
	return (0);
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
			if ((sym == 1 && words[w][i + 1] != '\0') ||
				(sym == 2 && words[w][i + 2] != '\0'))
			{
				com = sym + i;
				while (words[w][com])
				{
					if (m_ischar(&words[w][com], command) || words[w][com + 1] == '\0')
					{
						m_lstadd_back(&command, m_lst_intnew(ft_substr(words[w], i, com - i)));
						break ;
					}
					com++;
				}
				i += com;
			}
			if ((sym == 1 && words[w][i + 1] == '\0') ||
				(sym == 2 && words[w][i + 2] == '\0'))
			{
				com = 0;
				if (!words[w + 1] || !m_ischar(words[w + 1], command))
					break ;
				w++;
				while (words[w][com])
				{
					if (m_ischar(&words[w][com], command) || words[w][com + 1] == '\0')
					{
						m_lstadd_back(&command, m_lst_intnew(ft_substr(words[w], i, com - i)));
						break ;
					}
					com++;
				}
			}
			if (words[w][i + 1] == '\0' && sym == 0)
			{
				m_lstadd_back(&command, m_lst_intnew(ft_substr (words[w], init_word(words[w]), word_len(words[w])));
			}
			i++;
		}
		w++;
	}
	return (command);
}

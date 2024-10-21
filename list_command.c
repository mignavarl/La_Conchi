#include "prueba_mini.h"

void	list_cmd(t_cmds **command, char **words)
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
						printf("Aqui\n");
						command = ft_substr(words[w], i, com - i);
						command = command->next;
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
						command.cmd = ft_substr(ft_strjoin(&words[w - 1][i], words[w]), 0, com + 1);
						command = command.next;
						break ;
					}
					com++;
				}
			}
			i++;
		}
		w++;
	}
}

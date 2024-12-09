#include "minishell.h"
/* DESUSO
void	while_end(char *line, int i)
{
	char	*new;
	char	sym;

	sym = line[i];
	while (1)
	{
		new = readline("> ");
		if (!new)
			break ;
		line = ft_threejoin(line, "\n", new);
		if (sym == new[0])
		{
			free(new);
			break ;
		}
		free(new);
	}
	add_history(line);
	free(line);
} */

int	search_end_quote(char *line, int i)
{
	int f;
	char	sym;

	f = i + 1;
	sym = line[i];
	//printf("Sym: %c\n", sym);
	while (line[f])
	{
		//printf("sym = %c -- end line[%d] = %c\n", sym, f, line[f]);
		if (line[f] == sym)
		{
			return (1);
		}
		f++;
	}
	return (0);
}

char	*find_quote(char *line, int i)
{
	int 	l;
	char	*quote;

	// if (!search_end_quote(line, i))
	// {
	// 	while_end(line, i);
	// 	return (0);
	// }
	l = i + 1;
	while (line[l])
	{
		if ((line[i] == '"' && line[l] == '"') || (line[i] == '\'' && line[l] == '\''))
		{
			quote = ft_substr(&line[i], 1, (l - i) - 1);
			break ;
		}
		l++;
	}
	return (quote);
}

/* DESUSO
void	search_end_while(char *line)
{
	char	sym;
	int		i;
	int		l;

	i = 0;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\'')
		{
			sym = line[i];
			l = i + 1;
			while (line[l] || line[i + 1] == '\0')
			{
				if (line[l] == sym)
					break ;
				if (line[l + 1] =='\0' || line[l] == PIPE)
				{
					while_end(line, i);
					return ;
				}
				l++;
			}
		}
		i++;
	}
} */

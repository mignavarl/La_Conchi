/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 10:32:15 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-10 10:32:15 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*clean_line(char *line, int init, int end)
{
	char	*new_line;
	int		n;

	n = 0;
	new_line = ft_calloc(ft_strlen(line) - (end - init), sizeof(char));
	if (!new_line)
		return (NULL);
	while (n < init)
	{
		new_line[n] = line[n];
		n++;
	}
	while (line[end])
	{
		new_line[n] = line[end];
		n++;
		end++;
	}
	return (new_line);
}

char	*expand_var_quote(char *line, int init, t_env *env)
{
	char	*new_line;
	char	*var;
	char	*value;
	int		end;

	end = init + 1;
	while (line[end] && line[end] != ' ' && line[end] != '"')
		end++;
	if (line[end] == ' ' || line[end] == '"')
		end--;
	var = ft_substr(line, init, (end - init));
	value = get_env_var(env, var);
	if (!value)
	{
		free(var);
		free(value);
		return(clean_line(line, (init - 1), end));
	}
	new_line = update_line(line, (init - 1), end);//TODO:to do
}

char	*find_quote(char *line, int i, t_data *data, t_env *env)
{
	int 	l;
	int		n;
	char	*quote;
	char	*tmp_quote;

	l = i + 1;
	while (line[l])
	{
		if (line[l] == '$' && line[i] == '"')
			line = expand_var_quote(line, (l + 1), env);
		if ((line[i] == '"' && line[l] == '"') || (line[i] == '\'' && line[l] == '\''))
		{
			quote = ft_substr(&line[i], 1, (l - i) - 1);
			if (line[l + 1] != '\0' || line[l + 1] != ' ')
			{
				n = l + 1;
				while (line[n] && line[n] != ' ')
				{
					if (line[n] != '"' && line[n] != '\'')
					{
						tmp_quote = ft_strdup(quote);
						if (!tmp_quote)
							return (NULL);
						free(quote);
						quote = ft_joinchar(tmp_quote, line[n]);
						if (!quote)
							return (NULL);
					}
					n++;
				}
			}
			data->quote_chars = n;
			l = n - 1;
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

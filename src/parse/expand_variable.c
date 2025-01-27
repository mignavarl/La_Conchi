/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-27 15:00:07 by mignavar          #+#    #+#             */
/*   Updated: 2025-01-27 15:00:07 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*clean_line(char *line, int init, int end)
{
	char	*new_line;
	int		n;

	n = 0;
	new_line = ft_calloc(ft_strlen(line) - (end - init) + 1, sizeof(char));
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

char	*update_line(char *line, char *value, int init, int end)
{
	char	*new_line;
	int		n;
	int		v;

	n = 0;
	new_line = ft_calloc((ft_strlen(line) + ft_strlen(value) + 1), sizeof(char));
	if (!new_line)
		return (NULL);
	while (n < init)
	{
		new_line[n] = line[n];
		n++;
	}
	v = 0;
	while (value[v])
	{
		new_line[n] = value[v];
		n++;
		v++;
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
	var = ft_substr(line, init, (end - init));
	value = get_env_var(env, var);
	if (!value)
	{
		free(var);
		free(value);
		return(clean_line(line, (init - 1), end));
	}
	new_line = update_line(line, value, (init - 1), end);
	free(var);
	free(value);
	free(line);
	return (new_line);
}

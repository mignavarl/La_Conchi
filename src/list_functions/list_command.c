/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 10:30:32 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-10 10:30:32 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redir_in_middle(t_cmds **command, char **words, int i, t_data *data)
{
	int	com;

	com = data->sym_list + i;
	while (words[data->word_list][com])
	{
		if (m_ischar(&words[data->word_list][com])
		|| words[data->word_list][com + 1] == '\0')
		{
			m_lstadd_back(command, m_lst_intnew(
					ft_substr(words[data->word_list], i, data->sym_list)));
			break ;
		}
		com++;
	}
	i = com - 1;
	while (!m_ischar(&words[data->word_list][i]))
		i--;
	data->sym_list = m_ischar(&words[data->word_list][com]);
	return (i);
}

int	put_in_list(t_cmds **command, char **words, int i, t_data *data)
{
	if (data->sym_list == 0)
	{
		m_lstadd_back(command, m_lst_intnew(
				m_find_word(&words[data->word_list][i])));
		i = next_word(words[data->word_list], i);
		if (words[data->word_list][i] == '\0')
			i -= 1;
		if (words[data->word_list][i + 1] == '\0')
			return (-1);
		data->sym_list = m_ischar(&words[data->word_list][i]) - 1;
	}
	else if ((data->sym_list == 1 && words[data->word_list][i + 1] != '\0') ||
		(data->sym_list == 2 && words[data->word_list][i + 2] != '\0'))
		i = redir_in_middle(command, words, i, data);
	else if ((data->sym_list == 1 && words[data->word_list][i + 1] == '\0') ||
		(data->sym_list == 2 && words[data->word_list][i + 2] == '\0'))
	{
		m_lstadd_back(command, m_lst_intnew(ft_substr (words[data->word_list],
					find_last_sym(words[data->word_list]), data->sym_list)));
		return (-1);
	}
	return (i);
}

int	list_quote(t_cmds **command, char **words, t_data *data, int i)
{
	if (i == 0 && (words[data->word_list][i] == '"'
		|| words[data->word_list][i] == '\''))
	{
		m_lstadd_back_quote(command, m_lst_intnew(ft_substr(
					words[data->word_list], 1,
					(ft_strlen(words[data->word_list]) - 2))),
					words[data->word_list][i]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_cmds	*list_cmd(t_cmds *command, char **words, t_data *data)
{
	int	i;

	data->word_list = 0;
	data->sym_list = 0;
	while (words[data->word_list])
	{
		i = 0;
		while (words[data->word_list][i])
		{
			if (list_quote(&command, words, data, i))
				break ;
			data->sym_list = m_ischar(&words[data->word_list][i]);
			i = put_in_list(&command, words, i, data);
			if (i == -1)
				break ;
			i++;
		}
		data->word_list++;
	}
	return (command);
}

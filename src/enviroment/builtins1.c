/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond <osredond@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:23:30 by osredond          #+#    #+#             */
/*   Updated: 2024/11/23 21:48:36 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "env.h"

void	ft_myprintecho(char *echo, int flag)
{
	ft_putquotes(echo);
	if (flag == 0)
		write(1, "\n", 1);
	return ;
}

static int	ft_myecho(char *echo)
{
	int	flag;

	while (*echo == ' ')
		echo++;
	if (ft_strncmp(echo, "echo", 4) == 0)
		echo += 4;
	while (*echo == ' ')
		echo++;
	while (*echo == '-' && *(echo + 1) == 'n')
	{
		while (*echo == '-' || *echo == 'n')
			echo++;
		flag = 1;
		while (*echo == ' ')
			echo++;
	}
	if (*echo == '\0')
	{
		if (flag == 0)
			write(1, "\n", 1);
		return (0);
	}
	ft_myprintecho(echo, flag);
	return (0);
}

t_list	*builtins(void)
{
	t_list			*builtins;
	t_string		*command;
	char			**str;
	unsigned int	i;

	builtins = new_list();
	str = ft_split(BUILTS, ' ');
	i = 0;
	while (str[i] != NULL)
	{
		command = NULL;
		command = terminal_string(str[i]);
		builtins = insert_in_list(builtins, (void *)command);
		string_delete(command);
		free(command);
		i++;
	}
	ft_doublefree(str);
	return (builtins);
}

static int	echo_aux(char *prompt)
{
	int	res;

	if (ft_strlen(prompt) == 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
		res = ft_myecho(prompt);
	return (res);
}

int	terminator(t_tools *tools, char *prompt, int blt)
{
	int	res;

	res = 0;
	if (blt == BT_CD)
		res = ft_mychdir(prompt, tools);
	else if (blt == BT_ECHO)
		res = echo_aux(prompt);
	else if (blt == BT_EXPORT)
	{
		tools->exp = dup_matrix_envp(tools->env);
		res = ft_myexport(tools, prompt);
	}
	else if (blt == BT_UNSET)
		res = ft_myunset(tools, prompt);
	else if (blt == BT_ENV)
		ft_myenv(tools->env);
	else if (blt == BT_EXIT)
		ft_exit(prompt);
	else if (blt == BT_PWD)
		printf("%s\n", tools->pwd);
	return (res);
}*/
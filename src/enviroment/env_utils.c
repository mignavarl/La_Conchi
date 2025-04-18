/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-17 09:57:17 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-17 09:57:17 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*ft_strndup(char *str, size_t n)
{
	size_t	i;
	char	*copy;

	i = 0;
	if (!str)
		return (NULL);
	if (ft_strlen(str) > n)
		copy = ft_calloc(sizeof(char), n + 1);
	else
		copy = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!copy)
		return (NULL);
	while (str[i] && i < n)
	{
		copy[i] = str[i];
		i++;
	}
	return (copy);
}

int	env_lstsize(t_env *lst)
{
	t_env	*l;
	int		i;

	l = lst;
	i = 0;
	while (l != NULL)
	{
		i++;
		l = l->next;
	}
	return (i);
}

t_env	*env_last(t_env *lst)
{
	t_env	*l;

	l = lst;
	while (l != NULL)
	{
		if (l -> next == NULL)
			return (l);
		l = l -> next;
	}
	return (0);
}

void	env_add_back(t_env **lst, t_env *new)
{
	t_env	*now;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	now = env_last(*lst);
	now->next = new;
	new->next = NULL;
}

void	free_env(t_env *env_list)
{
	t_env	*tmp;

	while (env_list)
	{
		tmp = env_list;
		env_list = env_list->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	env_list = NULL;
}

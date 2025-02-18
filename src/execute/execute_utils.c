/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 10:31:27 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-10 10:31:27 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = ft_substr(envp[i], 1, ft_strlen(envp[i]));
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*search_route(char *command, char **envp)
{
	char	*path;
	char	**route;
	int		i;

	path = search_path(envp);
	if (!path)
		return (NULL);
	route = ft_split(path, ':');
	free(path);
	i = 0;
	while (route[i])
	{
		path = ft_threejoin(route[i], "/", command);
		if (access(path, F_OK) == 0)
		{
			ft_free_double(&route);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_double(&route);
	if (access(command, F_OK) == 0)
		return (ft_strdup(command));
	return (NULL);
}

char	**set_env(t_env *env)
{
	char	**envp;
	int		i;
	t_env	*tmp;

	tmp = env;
	i = 0;
	envp = ft_calloc(env_lstsize(env) + 1, sizeof(char *));
	if (!envp)
		return (NULL);
	while (tmp)
	{
		envp[i] = ft_threejoin(tmp->key, "=", tmp->value);
		if (!envp[i])
			return (ft_free_double(&envp), NULL);
		tmp = tmp->next;
		i++;
	}
	return (envp);
}

void	ft_safe_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

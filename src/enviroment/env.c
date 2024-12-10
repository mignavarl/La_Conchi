/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:23:30 by osredond          #+#    #+#             */
/*   Updated: 2024/11/23 21:48:36 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

// Implementación de las funciones

t_env *init_env(char **envp, t_env *env)
{
	int		i;
	char	*equal_sign;

	i = 0;
	while (envp[i])
	{
		equal_sign = strchr(envp[i], '=');
		if (equal_sign)
		{
			t_env *new_env = malloc(sizeof(t_env));
			new_env->key = strndup(envp[i], equal_sign - envp[i]);
			new_env->value = strdup(equal_sign + 1);
			new_env->next = env;
			env = new_env;
		}
		i++;
	}
	return (env);
}

void add_env_var(t_env **env_list, char *key, char *value)
{
	t_env *new_var = malloc(sizeof(t_env));
	new_var->key = strdup(key);
	new_var->value = strdup(value);
	new_var->next = *env_list;
	*env_list = new_var;
}

char *get_env_var(t_env *env_list, char *key)
{
	while (env_list)
	{
		if (strcmp(env_list->key, key) == 0)
			return env_list->value;
		env_list = env_list->next;
	}
	return NULL;
}

void free_env(t_env *env_list)
{
	t_env *tmp;

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
// Función para actualizar o agregar una variable de entorno
void update_env_var(t_env **env_list, char *key, char *value)
{
	t_env *current = *env_list;

	// Buscar si la variable ya existe
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			return;
		}
		current = current->next;
	}

	// Si no existe, agregar una nueva variable
	add_env_var(env_list, key, value);
}

// Función para eliminar una variable de entorno
void remove_env_var(t_env **env_list, char *key)
{
	t_env *current = *env_list;
	t_env *prev = NULL;

	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*env_list = current->next;

			free(current->key);
			free(current->value);
			free(current);
			return;
		}
		prev = current;
		current = current->next;
	}
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

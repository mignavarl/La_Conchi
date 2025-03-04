/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:34:48 by mignavar          #+#    #+#             */
/*   Updated: 2025/03/04 15:47:52 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

// Declaraciones de funciones
//ENV.C
t_env	*init_env(char **envp, t_env *env);
void	add_env_var(t_env **env_list, char *key, char *value);
char	*get_env_var(t_env *env_list, char *key);
void	update_env_var(t_env **env_list, char *key, char *value);
void	remove_env_var(t_env **env_list, char *key);

//ENV_UTILS.C
int		env_lstsize(t_env *lst);
t_env	*env_last(t_env *lst);
void	env_add_back(t_env **lst, t_env *new);
void	free_env(t_env *env_list);
char	*ft_strndup(char *str, size_t n);

#endif
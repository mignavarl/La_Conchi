/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 10:31:11 by mignavar          #+#    #+#             */
/*   Updated: 2024-12-10 10:31:11 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_pwd(void)
{
	char	*s;

	s = getcwd(NULL, 0);
	if (!s)
	{
		perror("Error al obtener el directorio actual");
		return ;
	}
	if (write(STDOUT_FILENO, s, ft_strlen(s)) == -1)
		perror("Error al imprimir el directorio actual");
	if (write(STDOUT_FILENO, "\n", 1) == -1)
		perror("Error al imprimir el salto de línea");
	free(s);
}

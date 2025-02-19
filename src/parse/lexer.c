/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:40:48 by osredond          #+#    #+#             */
/*   Updated: 2025/02/17 20:07:10 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*
lo que se hace aqui es simplemente evitar que hayan pipes solas, o cualquier elemento digase < | << > >> solo.
cuando un comando tipo ej:(ls | ) sucede deberia haber un error ya que la pipe esta sola, y lo mismo para cualquier token
asi que como he añadido pipes, podeis añadir con la misma logica para controlar  < << > >> y asi sucecivamente 
*/
// Es necesario hacer un parseo de todo AQUI, antes de pasarlo al executor, así el código es más limpio
int lexer(char *line)
{
    int i;

    i = 0;
	while(line[i])
	{
		if(line[i] == '|' && line[i + 1] == '|')
		{
			printf("La Conchi: syntax error near unexpected token `|'\n");
			return (free(line), EXIT_FAILURE);
		}
		else if(line[i] == '|' && !line[i + 1])
		{
			printf("La Conchi: syntax error near unexpected token `|'\n");
			return (free(line), EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS); // Retornar éxito si no hay errores de sintaxis
}

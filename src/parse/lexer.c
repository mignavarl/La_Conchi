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



    // int i = 0;

    // while (words[i]) // Iterar sobre cada palabra en el array
    // {
    //     //printf("[%s]", words[i]); // Imprimir la palabra actual

    //     // Si encontramos un pipe '|' sin tokens previos o al final, mostramos error
    //     if ((ft_strncmp(words[i], "|", 1) == 0) &&
    //         (i == 0 || !words[i + 1] || ft_strncmp(words[i + 1], "|", 1) == 0))
    //     {
    //         printf("Syntax Error\n");
    //         return (EXIT_FAILURE);
    //     }

    //     // Expansión de variables ()
    //     //if (words[i][0] == '$')
    //     {
    //         //otras variables ??
    //     }

    //     i++; // Avanzar al siguiente índice
    // }

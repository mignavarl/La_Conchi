/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osredond < osredond@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:40:48 by osredond          #+#    #+#             */
/*   Updated: 2024/12/09 18:28:16 by osredond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int lexer(char **words)
{
    int i = 0;

    while (words[i]) // Iterar sobre cada palabra en el array
    {
        //printf("[%s]", words[i]); // Imprimir la palabra actual

        // Si encontramos un pipe '|' sin tokens previos o al final, mostramos error
        if ((ft_strncmp(words[i], "|", 1) == 0) &&
            (i == 0 || !words[i + 1] || ft_strncmp(words[i + 1], "|", 1) == 0))
        {
            printf("Syntax Error\n");
            return (EXIT_FAILURE);
        }

        // Expansión de variables ()
        //if (words[i][0] == '$')
        {
            //otras variables ??
        }

        i++; // Avanzar al siguiente índice
    }

    return (EXIT_SUCCESS); // Retornar éxito si no hay errores de sintaxis
}




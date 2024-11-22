#include "prueba_mini.h"

// int	check_chars(char **words, t_chars *chars)//EN DESUSO
// {
// 	int	w;

// 	w = 0;
// 	while (words[w])
// 	{
// 		if (words[w][0] == PIPE && words[w][1] == 0)
// 			chars -> pipe++;
// 		else if (words[w][0] == INPUT && words[w][1] == 0)
// 			chars -> input++;
// 		else if (words[w][0] == OUTPUT && words[w][1] == 0)
// 			chars -> output++;
// 		else if (ft_strcmp(words[w], APPEND) == 0)
// 			chars -> append++;
// 		else if (ft_strcmp(words[w], DELIMITER) == 0)
// 			chars -> delim++;
// 		w++;
// 	}
// 	// if (!check_(words))
// 	// 	return (FALSE);
// 	return (TRUE);
// 	//printf("Pipe = %d\nInput = %d\nOutput = %d\nAppend = %d\nDelimiter = %d\n", chars->pipe, chars->input, chars->output, chars->append, chars->delim);
// }

//Return: 0 = no char. 1 = | < >. 2 = >> <<
int	m_ischar(char *c)
{
	if (c == NULL || (c[0] == '\0'))
		return 0; 
	if (ft_strlen(c) > 1)
	{
		if ((ft_strncmp(c, APPEND, 2) == 0 || ft_strncmp(c, DELIMITER, 2) == 0) &&
			(c[2] != PIPE && c[2] != INPUT && c[2] != OUTPUT))
		{
			return (2);
		}
	}
	if ((c[0] == PIPE || c[0] == INPUT || c[0] == OUTPUT))
	{
		return (1);
	}
	return (0);
}


#include "prueba_mini.h"

int	check_chars(char **words, t_chars *chars)
{
	int	w;

	w = 0;
	while (words[w])
	{
		if (words[w][0] == PIPE && words[w][1] == 0)
			chars -> pipe++;
		else if (words[w][0] == INPUT && words[w][1] == 0)
			chars -> input++;
		else if (words[w][0] == OUTPUT && words[w][1] == 0)
			chars -> output++;
		else if (ft_strcmp(words[w], APPEND) == 0)
			chars -> append++;
		else if (ft_strcmp(words[w], DELIMITER) == 0)
			chars -> delim++;
		w++;
	}
	// if (!check_(words))
	// 	return (FALSE);
	return (TRUE);
	//printf("Pipe = %d\nInput = %d\nOutput = %d\nAppend = %d\nDelimiter = %d\n", chars->pipe, chars->input, chars->output, chars->append, chars->delim);
}

//Return: 0 = no char. 1 = | < >. 2 = >> <<
int	m_ischar(char *c, t_cmds *node)
{
	if ((ft_strncmp(c, APPEND, 2) == 0 || ft_strncmp(c, DELIMITER, 2) == 0) &&
		(c[2] != PIPE || c[2] != INPUT || c[2] != OUTPUT))
		{
			if (c[0] == INPUT && node)
				node->delim = 1;
			else if (c[0] == OUTPUT && node)
				node->append = 1;
			return (2);
		}
	if ((c[0] == PIPE || c[0] == INPUT || c[0] == OUTPUT) &&
		(c[1] != PIPE || c[1] != INPUT || c[1] != OUTPUT))
		{
			if (c[0] == PIPE && node)
				node->pipe = 1;
			else if (c[0] == INPUT && node)
				node->input = 1;
			else if (c[0] == OUTPUT && node)
				node->output = 1;
			return (1);
		}
	return (0);
}

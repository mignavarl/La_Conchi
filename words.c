#include "prueba_mini.h"

char *find_words(char *line, int i)
{
	int		l;
	char	*word;

	l = i;
	while(line[l])
	{
		if (line[l] == ' ' || line[l] == '\0' || line[l] == '"' || line[l] == '\'')
			break ;
		l++;
	}
	word = ft_substr(line, i, (l - i));
	if (!word)
		return (NULL);
	return (word);
}

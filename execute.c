#include "prueba_mini.h"

void	execute_pwd()
{
	char	*s;

	s = malloc(100 * sizeof(char));
	printf("%s\n", getcwd(s, 100));
	free(s);
}

void	execute_cd(char **words, int num_words)
{
	if (num_words > 2)
	{
		printf("cd: too many arguments\n");
		return ;
	}
	else
		chdir(words[1]);
}

void	execute_cmds(char **words, int num_words)
{
	if (!ft_strcmp(words[0], "cd"))
		execute_cd(words, num_words);
	if (!ft_strcmp(words[0], "pwd"))
		execute_pwd();
}

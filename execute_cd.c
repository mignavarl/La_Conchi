#include "prueba_mini.h"

void execute_cd(char **command)
{
	int	i;

	i = 0;
	while (command[i])
		i++;
	if (i != 2)
	{
		printf("cd: too many arguments\n");
		return ;
	}
	if (chdir(command[1]) == -1)
		printf("cd: %s: No such file or directory\n", command[1]);
}

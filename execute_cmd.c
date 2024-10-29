#include "prueba_mini.h"

void	execute_pwd()
{
	char	*s;

	s = malloc(100 * sizeof(char));
	printf("%s\n", getcwd(s, 100));
	free(s);
}

void	execute_cd(char *cd, t_cmds *command)
{
	// if (num_words > 2)
	// {
	// 	printf("cd: too many arguments\n");
	// 	return ;
	// }
	// else
	// 	chdir(words[1]);
	t_cmds *tmp;

	tmp = command;
	if (tmp->next == NULL)
	{
		printf("cd: too many arguments\n");
		return ;
	}
	tmp = tmp->next;
	if (chdir(tmp->cmd) == -1)
		printf("cd: %s: No such file or directory\n", tmp->cmd);
}

void	execute_cmds(t_cmds *command)
{
	if (!ft_strcmp(command->cmd, "cd"))
		execute_cd(command->cmd, &command);
	if (!ft_strcmp(command->cmd, "pwd"))
		execute_pwd();
}

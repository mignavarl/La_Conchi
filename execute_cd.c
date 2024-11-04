#include "prueba_mini.h"

void execute_cd(t_cmds *command)
{
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

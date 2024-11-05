#include "prueba_mini.h"

void	execute_cmds(t_cmds *command)
{
	if (!ft_strcmp(command->cmd, "cd"))
		execute_cd(command);
	if (!ft_strcmp(command->cmd, "pwd"))
		execute_pwd();
	// else
	// 	execute_rest(command);//TODO:execute_rest.c
}

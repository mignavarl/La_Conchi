#include "prueba_mini.h"

void	execute_cmd(char **command, t_env *env)
{
	if (!command || !env)
		return ;//TODO:funcion salir
	if (!ft_strcmp(command[0], "cd"))
		execute_cd(command);
	else if (!ft_strcmp(command[0], "pwd"))
		execute_pwd();
	else
		execute_rest(command, env);
	if (command)
			ft_free_double(command);
}

#include "prueba_mini.h"

char	**set_env(t_env *env)
{
	char	**envp;
	t_env	*tmp;
	int		i;

	envp == malloc((m_lstsize(env) + 1) * sizeof(char *));
	if (!envp)
		return (NULL);
	tmp = env;
	i = 0;
	while (tmp)
	{
		envp[i] = ft_strdup(tmp->value);
		if (!envp[i])
			return (ft_free_double(envp), NULL);
		tmp = tmp->next;
		i++;
	}
	return (envp);
}

void	child(char **command, t_env *env)
{
	char	**envp;
	char	*route;

	envp = set_env(env);
	route = search_route(command[0], envp);
	execve(route, command, envp);
}

void	make_pipe(char **command, t_env *env)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid < 0)
		perror("Fork mal hecho");//TODO:funcion para salir
	if (pid == 0)
	{
		close(pipefd[READ]);
		dup2(pipefd[WRITE], STDOUT_FILENO);
		close(pipefd[WRITE]);
		child(command, env);
	}
	else
	{
		close(pipefd[WRITE]);
		dup2(pipefd[READ], STDIN_FILENO);
		close(pipefd[READ]);
	}
}

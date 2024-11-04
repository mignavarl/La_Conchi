#include "prueba_mini.h"

void	execute_pwd(void)
{
	char	*s;

	s = malloc(100 * sizeof(char));
	printf("%s\n", getcwd(s, 100));
	free(s);
}

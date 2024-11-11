#include "prueba_mini.h"

void	execute_pwd(void)
{
	char	*s;

	s = getcwd(NULL, 0);
	printf("%s\n", s);
	free(s);
}

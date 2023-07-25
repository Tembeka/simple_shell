#include "hell.h"

/**
 *
 *
 *
 *
 */

int handle_env(char *comm)
{
	if (strcmp(comm, "env") == 0)
	{
		char **env = environ;

		while (*env != NULL)
		{
			printf("%s\n", *env);
			env++;
		}
		return (1);
		}
	return (0);
}

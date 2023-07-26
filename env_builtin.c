#include "hell.h"

/**
 * handle_env - Implement the env built-in
 * @comm: str
 *
 * Return: 0 on success
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

#include "hell.h"

/**
 * handle_exit- Implement the exit built-in, that exits the shell
 * @comm: str
 *
 * Return: 0 on success
 */

int handle_exit(char* comm)
{
	if (strcmp(command, "exit") == 0)
	{
		printf("Shell exit.\n");
		return (1);
	}
	return(0);
}

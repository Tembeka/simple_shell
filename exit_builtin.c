#include "hell.h"

/**
 *
 *
 *
 *
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

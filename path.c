#include "hell.h"

/**
 * file - Handle the PATH 
 * @dir:
 * @file:
 *
 * Return:
 */

int file(const char* dir, const char* file)
{
	char path[MAX_COMMAND_LENGTH];

	snprintf(path, sizeof(path), "%s/%s", dir, file);

	return (access(path, F_OK) == 0);
}

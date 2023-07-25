#include "hell.h"

/**
 * remov - Handle command lines with arguments
 * @str: a string
 *
 * Return: string
 */

char* remov(char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;

	if (*str == 0)
		return (str);
	char* end = str + strlen(str) - 1;

	while (end > str && (*end == ' ' || *end == '\t' || *end == '\n'))
        end--;
	*(end + 1) = 0;
	return (str);
}

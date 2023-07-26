#include "hell.h"

/**
 *getline - getline func
 *@lineptr: pointer var
 *@n: input argument 
 *@stream:  pointer to a FILE structure
 *
 * Return:num of chars,  -1 EOF.
 */

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static char *buf_pos = buffer;
	static int buf_chars = 0;
	
	ssize_t chars_read = 0;
	ssize_t total_chars = 0;
	char *line = *lineptr;

	if (line == NULL || n == 0)
	{
		*n = BUFFER_SIZE;
		line = (char*)malloc(*n);
		if (line == NULL)
		{
			return (-1);
		}
	}
	while (1)
	{
		if (buffer_chars == 0)
		{
			buffer_chars = read(fileno(stream), buffer, BUFFER_SIZE);
			if (buf_chars <= 0)
			{
				if (total_chars == 0)
				{
					return (-1);
				}
				else
				{
					break;
				}
			}
			buffer_pos = buffer;
			while (chars_read < buffer_chars)
			{
				if (chars_read < buffer_chars)
				{
					if (total_chars >= *n - 1)
					{
						*n *= 2;
						line = (char*)realloc(line, *n);
						if (line == NULL)
						{
							return (-1);
						}
					}
					if (*buffer_pos == '\n')
					{
						*buffer_pos = '\0';
						line[total_chars++] = *buffer_pos++;
						buffer_chars--;
						chars_read++;
						return (total_chars);
					}
					line[total_chars++] = *buffer_pos++;
					buffer_chars--;
					chars_read++;
				}
			}
			line[total_chars] = '\0';
			*lineptr = line;
			return (total_chars);
}

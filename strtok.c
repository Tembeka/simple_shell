#include "hell.h"

int split_input(char* input, char** args)
{
	int argc = 0;
	char* word = NULL;

	while (*input)
	{
		while (isspace(*input))
		{
			input++;
		}
		if (*input == '\0')
		{
			break;
		}
		word = input;
		while (*input && !isspace(*input))
		{
			input++;
		}
		if (input != word)
		{
			*input = '\0';
			args[argc++] = word;
		}
	}
	args[argc] = NULL;
	return (argc);
}

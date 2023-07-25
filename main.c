#include "hell.h"

/**
 * main - main function.
 *
 * Return:0 on success.
 */

int comm_execution(char *comm);

int main(void)
{
	char comm[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("YourShell> ");

		if (fgets(comm, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			 printf("\n");
			 break;
		}
		comm[strcspn(comm, "\n")] = '\0';

		if (strlen(comm) > 0)
		{
			int result = comm_execution(trimmed_command);
			int is_exit = handle_exit(trimmed_command);

			if (is_exit)
				break;
			 int is_env = handle_env (trimmed_command);
			 
			 if (is_env)
				 continue;
			 char* trimmed_command = trim(comm);

			 if (result == -1)
				printf("Command not found.\n");
			 else if (result != 0)
				 printf("Executon error.\n");
		}
	}
	return (0);
}

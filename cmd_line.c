#include "hell"

/**
 * comm_execution - command line interpreter
 * @cmad: command to be executed
 *
 * Return:On success, execve() does not return, on error -1, and errno is set
 */

int comm_execution(char *cmad)
{
	char *args[MAX_ARGS] = {NULL};
	int argc = 0;
	char *token = strtok(cmad, " ");

	while (token != NULL && argc < MAX_ARGS - 1)
	{
		args[argc] = token;
		argc++;
		token = strtok(NULL, " ");
	}

	char *path_env = getenv("PATH");

	if (path_env == NULL)
	{
		printf("PATH not set.\n");
		return (-1);
	}

	char *path_token = strtok(path_env, ":");
	
	while (path_token != NULL)
	{
		if (file_exists(path_token, args[0]))
		{
			pid_t child_pid = fork();

			if (child_pid < 0)
			{
				perror("Forking error");
				return (1);
			}
			else if (child_pid == 0)
			{
				execvp(args[0], args);
				perror("execution error");
				exit(1);
			}
			else
			{
				int a;

				waitpid(child_pid, &a, 0);
				if (WIFEXITED(a))
				{
					int exit_a = WEXITSTATUS(a);

					return (exit_a);
				}
				else
				{
					return (1);
				}
			}
		}
		path_token = strtok(NULL, ":");
	
	}
	return (-1);
}

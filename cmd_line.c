#include "hell"

/**
 * comm_execution - command line interpreter
 * @cmad: command to be executed
 *
 * Return:On success, execve() does not return, on error -1, and errno is set
 */

int comm_execution(char* cmad)
{
	pid_t child_pid = fork();
	
	if (child_pid < 0)
	{
		perror("Forking error");
		return (1);
	}
	else if (child_pid == 0)
	{
		char* argv[] = {cmad, NULL};
		extern char** environ;

		execve(cmad, argv, environ);
		perror("Command execution error");
		exit(1);
	}
	else
	{
		int a;

		waitpid(child_pid, &a, 0);
		return (1);
	}
}

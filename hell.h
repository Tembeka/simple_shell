#define HELL_H
#ifdef HELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

int comm_execution(char* command);
int main(void);
int execve(const char *pathname, char *const argv[], char *const envp[]);

#endif

#define HELL_H
#ifdef HELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

char* remov(char* str);
int file(const char* dir, const char* file);
int handle_exit(char* comm);
int comm_execution(char* command);
int main(void);
int execve(const char *pathname, char *const argv[], char *const envp[]);

#endif

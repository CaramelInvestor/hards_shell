#include "shell.h"

/**
 * _exec - Executes the program with an array of token given.
 * @args: List of tokens to be read and executed.
 */

void _exec(char **args)
{
	pid_t child_pid = fork();
	int status;

	if (child_pid == 0)
	{
		execvp(args[0], args);
		perror("error");
		exit(1);
	}
	else if (child_pid > 0)
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("error");
	}
}

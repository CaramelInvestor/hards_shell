#include "shell.h"

/**
 * print_env - prints the environment variable..
 */

void print_env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		_puts(*env);
		_puts("\n");
		env++;
	}
}

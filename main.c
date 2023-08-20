#include "shell.h"

/**
 * main - entry point of my shell program
 * Return: returns 0 on success
 */
int main(void)
{
	size_t bufferSize = 0;
	ssize_t bytesRead;

	char *line;
	char **tokens;

	while ((bytesRead = getline(&line, &bufferSize, stdin)) != -1)
	{
		/*Ignore the line if it starts with a comment character*/
		if (line[0] == '#')
			continue;

		tokens = split_line(line);

		if (tokens[0] != NULL)
		{
			/* Check for the exit built-in command */
			if (my_strcmp(tokens[0], "exit") == 0)
			{
				if (tokens != NULL)
					free(tokens);
				break;
			}
			if (my_strcmp(tokens[0], "pwd") == 0) {
				def_current_dir();
				continue;
			}

			/* Check for the env built-in command */
			if (my_strcmp(tokens[0], "env") == 0)
			{
				print_env();
				continue;
			}
			/* Check for the setenv built-in command */
			if (my_strcmp(tokens[0], "setenv") == 0) {
				if (tokens[1] != NULL && tokens[2] != NULL) {
					/* Call def_setenv to set the environment variable */
					def_setenv(tokens[1], tokens[2]);
				} else {
					def_fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
				}
				continue;
			}

			/* Check for the unsetenv built-in command */
			if (my_strcmp(tokens[0], "unsetenv") == 0) {
				if (tokens[1] != NULL) {
					/* Call def_unsetenv to unset the environment variable */
					def_unsetenv(tokens[1]);
				} else {
					def_fprintf(stderr, "Usage: unsetenv VARIABLE\n");
				}
				continue;
			}
			_execme(tokens);
			free(tokens);
		}

	}
	if (line != NULL)
		free(line);
	return (0);
}

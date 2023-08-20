#include "shell.h"

/**
 *
 */

/* Define a list of allowed commands */
const char *allowed_commands[] = {
	"ls",
	"cat",
	"mkdir",
	"rmdir",
	/* Add more allowed commands as needed */
	NULL /* End of the list*/
};

/* Function to validate a command */
int def_valid_command(const char *command) {
	int i = 0;
	while (allowed_commands[i] != NULL) {
		if (strcmp(command, allowed_commands[i]) == 0) {
			return 1; /* Command is valid*/
		}
		i++;
	}
	return 0; /* Command is not valid*/
}

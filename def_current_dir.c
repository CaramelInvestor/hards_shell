#include "shell.h"

/**
 *
 */

void def_current_dir()
{
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL) {
		printf("Current directory: %s\n", cwd);
	} else {
		perror("getcwd");
	}
}

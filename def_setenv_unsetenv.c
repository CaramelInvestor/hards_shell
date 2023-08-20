#include "shell.h"

/**
 *
 */

int def_setenv(const char *variable, const char *value)
{
	if (variable == NULL || value == NULL) {
		def_fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return -1;
	}

	if (setenv(variable, value, 1) != 0) {
		perror("setenv");
		return -1;
	}

	return 0;
}

/**
 *
 */

int def_unsetenv(const char *variable)
{
	if (variable == NULL) {
		def_fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return -1;
	}

	if (unsetenv(variable) != 0) {
		perror("unsetenv");
		return -1;
	}

	return 0;
}

#include "shell.h"

/**
 *
 */
int def_fputs(const char *str, FILE *stream)
{
	int written = 0;

	if (str == NULL || stream == NULL) {
		return EOF;
	}

	while (*str != '\0') {
		int result = fputc(*str, stream);

		if (result == EOF) {
			return EOF;
		}

		str++;
		written++;
	}

	return written;
}

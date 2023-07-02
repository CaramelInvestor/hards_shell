#include <stdarg.h>
#include <stdio.h>
#include "shell.h"
/**
 * _printfs - function to print strings
 *@format: character pointer
 */
void _printfs(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
					{
						int value = va_arg(args, int);

						printf("%d", value);
						break;
					}
				case 's':
					{
						char *value = va_arg(args, char *);

						printf("%s", value);
						break;
					}
				default:
					putchar(*format);
					break;
			}
		}
		else
		{
			putchar(*format);
		}
		format++;
	}

	va_end(args);
}

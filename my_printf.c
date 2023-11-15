#include "main.h"
/**
 * _printf - A function that works exactly as the
 * standard printf function.
 * @format: format specifier
 * Return: number of bytes
 */

int _printf(const char *format, ...)
{
	unsigned int length_str, counts = 0;
	char char_print, *string;

	va_list args_lists;

	if (format == NULL) /* if nothing is passed to it */
	{
		return (-1);
	}
	va_start(args_lists, format);
	while (*format) /* checks the arguments passed */
	{
		if (*format != '%') /* if format is any other thing except % */
		{
			write(1, format, 1);
			counts++;
		}
		else /* if % */
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				char_print= va_arg(args_lists, int);
				write(1, &char_print, 1);
				counts++;
			}
			else if (*format == 's')
			{
				string = va_arg(args_lists, char *);
				length_str = strlen(string);
				write(1, string, length_str);
				counts += length_str;
			}
			else if (*format == '%') /* if passed %% print % */
			{
				write(1, format, 1);
				counts++;
			}
		}
		format++; /* keep checking */
	}
	va_end(args_lists); /* end */
	return (counts);
}

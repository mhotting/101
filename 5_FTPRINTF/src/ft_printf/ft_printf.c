#include "./../../includes/libft.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	printf("Chaine donnee: %s", format);
	va_end(ap);
	return (1);
}

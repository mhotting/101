#include "./../../includes/libft.h"
#include <stdio.h>

/* EXTRACT FROM STRING */
size_t	ft_endformat(char *format, size_t i)
{
	size_t	j;

	j = 0;
	return (j);
}

/* PRINTF FUNCTIONS */

void	ft_putarg(va_list ap, char *format, size_t i)
{
	return ;
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			ft_putarg(ap, format, i);
		i++;
	}
	ft_putstr(format);
	va_end(ap);
	return (ft_strlen(format));
}

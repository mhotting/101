/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 14:02:32 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 18:51:42 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"
#include <stdio.h>

static void	ft_dispatch(char *str, size_t i, va_list *ap)
{
	int	x;

	x = va_arg(*ap, unsigned int);
	if (str[i] == '%')
	{
		ft_putstr("Le nbr est: ");
		ft_putnbr(x);
		ft_putendl("");
	}
}

int		ft_printf(const char *format, ...)
{
	char	*str;
	va_list	ap;
	int		len_ret;
	size_t	i;

	if (format == NULL)
		return (0);
	str = ft_strdup(format);
	va_start(ap, format);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ft_dispatch(str, i, &ap);
		i++;
	}
	ft_putstr(str);
	va_end(ap);
	len_ret = (int)ft_strlen(str);
	free(str);
	return (len_ret);
}

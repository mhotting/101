/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_f_arg.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 12:07:54 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/23 19:49:00 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../../includes/libft.h"
#include <stdio.h>

char	*pf_f_arg(char *sub, va_list ap)
{
	char		*res;
	long double	f;

	if (sub != NULL)
		;
	f = va_arg(ap, long double);
	printf("Value: %Lf\n", f);
	res = ft_strdup("TEMP");
	return (res);
}

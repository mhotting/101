/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_int_arg.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 16:22:47 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 18:58:28 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../../includes/libft.h"
#include <stdio.h>

char		*pf_int_arg(char *sub, va_list *ap, t_attributes *att)
{
	char	*res;
	int		x;

	if (sub != NULL && att != NULL)
		;
	x = va_arg(*ap, int);
	res = ft_itoa(x);
	return (res);
}

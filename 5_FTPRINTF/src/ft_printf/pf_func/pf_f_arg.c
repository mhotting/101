/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_f_arg.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 12:07:54 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 18:58:08 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../../includes/libft.h"
#include <stdio.h>

char	*pf_f_arg(char *sub, va_list *ap, t_attributes *att)
{
	char		*res;
	long double	f;

	if (sub != NULL && att != NULL)
		;
	f = va_arg(*ap, double);
	res = ft_ldtoa(f, 6);
	return (res);
}

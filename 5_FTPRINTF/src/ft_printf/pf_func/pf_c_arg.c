/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_c_arg.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 11:29:21 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/23 12:12:15 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../../includes/libft.h"

char	*pf_c_arg(char *sub, va_list *ap)
{
	char	*res;
	char	c;

	if (sub != NULL)
		;
	c = (char)va_arg(*ap, int);
	res = ft_ctoa(c);
	return (res);
}

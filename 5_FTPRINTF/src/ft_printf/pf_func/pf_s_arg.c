/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_s_arg.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 11:26:43 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 05:34:24 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../../includes/libft.h"

char	*pf_s_arg(char *sub, va_list *ap, t_attributes *att)
{
	char	*res;

	if (sub != NULL && ap != NULL && att != NULL)
		;
	res = va_arg(*ap, char *);
	if (res == NULL)
		return (ft_strdup("(null)"));
	res = ft_strdup(res);
	return (res);
}

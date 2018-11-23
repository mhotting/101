/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_p_arg.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 11:41:53 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/23 12:07:19 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../../includes/libft.h"

char	*pf_p_arg(char *sub, va_list *ap)
{
	char					*res;
	void					*arg;
	long long unsigned int	addr;

	if (sub != NULL)
		;
	arg = va_arg(*ap, void *);
	addr = (long long unsigned int)arg;
	//res = ft_lluitoabase(addr, 16);
	res = ft_strdup("TEMP");
	return (res);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_p_arg.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 11:41:53 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 20:30:02 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../../includes/libft.h"

char	*pf_p_arg(char *sub, va_list *ap, t_attributes *att)
{
	char					*res;
	void					*arg;
	long long unsigned int	addr;

	if (sub)
		;
	arg = va_arg(*ap, void *);
	addr = (long long unsigned int)arg;
	res = ft_uitoabase(addr, 16);
	ft_enhance_left(&res, 'x', ft_strlen(res) + 1);
	ft_enhance_left(&res, '0', ft_strlen(res) + 1);
	if (att->width != -1)
	{
		if (att->opt1 == 1)
			ft_enhance_right(&res, ' ', att->width);
		else
			ft_enhance_left(&res, ' ', att->width);
	}
	return (res);
}

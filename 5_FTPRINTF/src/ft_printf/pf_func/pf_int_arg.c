/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_int_arg.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 16:22:47 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 23:57:46 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../../includes/libft.h"
#include <stdio.h>

static char				*ft_toa(char *sub, long long int x, t_attributes *att)
{
	char	end;
	char	*res;

	res = NULL;
	end = sub[ft_strlen(sub) - 1];
	if (end == 'd' || end == 'i')
		res = ft_itoa(x);
	else if (end == 'u')
		res = (att->l == 0 && att->ll == 0 ?
				ft_uitoa((unsigned)x) : ft_uitoa(x));
	else if (end == 'o')
		res = (att->l == 0 && att->ll == 0 ?
				ft_uitoabase((unsigned)x, 8) : ft_uitoabase(x, 8));
	else if (end == 'x' || end == 'X')
	{
		res = (att->l == 0 && att->ll == 0 ?
				ft_uitoabase((unsigned)x, 16) : ft_uitoabase(x, 16));
		if (end == 'X')
			ft_strtoupper(res);
	}
	if (res == NULL)
		return (NULL);
	return (res);
}

static long long int	ft_ext(va_list *ap, t_attributes *att)
{
	long long int	x;

	if (att->hh == 1 || att->h == 1)
		x = va_arg(*ap, int);
	else if (att->l == 1)
		x = va_arg(*ap, long int);
	else if (att->ll == 1)
		x = va_arg(*ap, long long int);
	else
		x = va_arg(*ap, int);
	return (x);
}

char					*pf_int_arg(char *sub, va_list *ap, t_attributes *att)
{
	char				*res;
	long long int		x;

	if (sub != NULL && att != NULL)
		;
	x = ft_ext(ap, att);
	res = ft_toa(sub, x, att);
	return (res);
}

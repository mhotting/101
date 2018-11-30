/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_int_arg.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 16:22:47 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 13:09:00 by mhotting    ###    #+. /#+    ###.fr     */
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
	if (x == 0 && att->prec == 0)
		ft_delzero(&res);
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

static void				ft_applyflag(char **res, char *sub, long long int x,
		t_attributes *att)
{
	char	end;

	end = sub[ft_strlen(sub) - 1];
	if (att->prec != -1)
		ft_enhance_left(res, '0', (x < 0 ? att->prec + 1 : att->prec));
	if (x >= 0 && (end == 'd' || end == 'i'))
	{
		if (att->opt2 >= 1)
			ft_enhance_left(res, '+', (int)ft_strlen(*res) + 1);
		else if (att->opt5 == 1)
			ft_enhance_left(res, ' ', (int)ft_strlen(*res) + 1);
	}
	if (att->opt3 == 1 && end == 'x' && x != 0)
	{
		ft_enhance_left(res, 'x', (int)ft_strlen(*res) + 1);
		ft_enhance_left(res, '0', (int)ft_strlen(*res) + 1);
	}
	if (att->opt3 == 1 && end == 'X' && x != 0)
	{
		ft_enhance_left(res, 'X', (int)ft_strlen(*res) + 1);
		ft_enhance_left(res, '0', (int)ft_strlen(*res) + 1);
	}
	if (att->opt3 == 1 && end == 'o')
		ft_enhance_left(res, '0', (int)ft_strlen(*res) + 1);
}

static void				ft_applyflag2(char **res, char *sub, t_attributes *att)
{
	char	end;

	end = sub[ft_strlen(sub) - 1];
	if (att->width != -1)
	{
		if (att->opt1 == 0)
		{
			if (att->opt4 == 0 || (att->prec != -1))
				ft_enhance_left(res, ' ', att->width);
			else
				ft_enhance_left(res, '0', att->width);
		}
		else
			ft_enhance_right(res, ' ', att->width);
	}
	ft_intadjust(*res, att);
}

char					*pf_int_arg(char *sub, va_list *ap, t_attributes *att)
{
	char				*res;
	long long int		x;

	if (sub != NULL && att != NULL)
		;
	x = ft_ext(ap, att);
	res = ft_toa(sub, x, att);
	ft_applyflag(&res, sub, x, att);
	ft_applyflag2(&res, sub, att);
	return (res);
}

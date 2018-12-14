/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dtoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/25 10:07:50 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 18:01:17 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

static void	ft_extra_digit(char **res)
{
	char	*temp;
	size_t	len;
	int		i;

	len = ft_strlen(*res);
	temp = ft_strnew(len + 1);
	if (temp == NULL)
		return ;
	ft_strcpy(temp, *res);
	i = (int)len;
	while (i > 0)
	{
		temp[i] = temp[i - 1];
		i--;
	}
	if (temp[0] == '-')
		temp[1] = '1';
	else
		temp[0] = '1';
	free(*res);
	*res = temp;
}

static void	ft_rounder(char **res, int num, int index)
{
	if (num < 5)
		return ;
	if ((*res)[index] == '.')
	{
		ft_rounder(res, num, index - 1);
		return ;
	}
	if ((*res)[index] == '9' &&
			(index == 0 || ((*res)[0] == '-' && index == 1)))
	{
		(*res)[index] = '0';
		ft_extra_digit(res);
		return ;
	}
	if ((*res)[index] < '9')
	{
		(*res)[index] += 1;
		return ;
	}
	else
	{
		(*res)[index] = '0';
		ft_rounder(res, 6, index - 1);
	}
}

static void	ft_neg(int *index, long double *f, char *res)
{
	res[0] = '-';
	index[0]++;
	*f = *f * -1;
}

static void	ft_decimal(char *res, int prec, long double *f, int *index)
{
	int	int_part;
	int	d;

	d = 0;
	while (d < prec)
	{
		*f = *f * 10;
		int_part = (int)(*f);
		res[index[0]] = int_part + '0';
		index[0]++;
		*f = *f - (long double)int_part;
		d++;
	}
}

static int	ft_eval_size(long double f)
{
	int	res;

	if (f >= 0L && f < 1L)
		return (0);
	res = 0;
	while (!(f >= 0L && f < 1L))
	{
		f /= 10;
		res++;
	}
	return (res - 1);
}

static void	ft_resize(long double *temp, int size, int type)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (type == 1)
			*temp = *temp * 10;
		else
			*temp = *temp / 10;
		i++;
	}
}

void		ft_ldint_extract(char *res, long double *f)
{
	int			size;
	int			ext;
	long double	temp;
	int			i;

	i = (res[0] == '-' ? 1 : 0);
	size = ft_eval_size(*f);
	if (size == 0)
	{
		res[i] = '0';
		return ;
	}
	while (size >= 0)
	{
		temp = *f;
		ft_resize(&temp, size, -1);
		ext = (int)temp;
		res[i++] = ext + '0';
		temp = (long double)ext;
		ft_resize(&temp, size, 1);
		size--;
		*f -= temp;
	}
}

char		*ft_ldtoa(long double f, int prec)
{
	char			*temp;
	char			*res;
	int				index[2];

	index[0] = 0;
	if ((res = ft_strnew(LDBLMAXSIZE)) == NULL)
		return (NULL);
	if ((index[1] = 0) == 0 && f < 0)
		ft_neg(index, &f, res);
	ft_ldint_extract(res, &f);
	index[0] = (int)ft_strlen(res);
	if (prec > 0)
		res[index[0]++] = '.';
	ft_decimal(res, prec, &f, index);
	ft_rounder(&res, (int)(f * 10), index[0] - 1);
	temp = res;
	res = ft_strdup(res);
	free(temp);
	return (res);
}

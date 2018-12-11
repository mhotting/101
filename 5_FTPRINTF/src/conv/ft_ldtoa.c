/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dtoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/25 10:07:50 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 19:15:11 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"
#include <stdio.h>

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

char		*ft_ldtoa(long double f, int prec)
{
	char			*temp;
	char			*res;
	int				index[2];
	long long int	int_part;

	index[0] = 0;
	if ((res = ft_strnew(30 + prec)) == NULL)
		return (NULL);
	if ((index[1] = 0) == 0 && f < 0)
		ft_neg(index, &f, res);
	int_part = (long long int)f;
	if ((temp = ft_itoa(int_part)) == NULL)
		return (NULL);
	while (index[1] < (int)ft_strlen(temp))
		res[index[0]++] = temp[index[1]++];
	if (prec > 0)
		res[index[0]++] = '.';
	free(temp);
	f -= (long double)int_part;
	ft_decimal(res, prec, &f, index);
	ft_rounder(&res, (int)(f * 10), index[0] - 1);
	temp = res;
	res = ft_strdup(res);
	free(temp);
	return (res);
}

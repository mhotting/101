/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dtoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/25 10:07:50 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 13:20:51 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

static void	ft_neg(size_t *index, long double *f, char *res)
{
	res[0] = '-';
	index[0]++;
	*f = *f * - 1;
}

static void	ft_decimal(char *res, int prec, long double *f, size_t *index)
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
		*f = *f - int_part;
		d++;
	}
}

char	*ft_ldtoa(long double f, int prec)
{
	int		int_part;
	char	*temp;
	char	*res;
	size_t	index[2];

	if ((res = ft_strnew(30 + prec)) == NULL)
		return (NULL);
	index[0] = 0;
	if ((index[1] = 0) == 0 && f < 0)
		ft_neg(index, &f, res);
	int_part = (int)f;
	temp = ft_itoa(int_part);
	while (index[1] < ft_strlen(temp))
		res[index[0]++] = temp[index[1]++];
	if (prec > 0)
		res[index[0]++] = '.';
	free(temp);
	f -= int_part;
	ft_decimal(res, prec, &f, index);
	if ((int)(f * 10) >= 5)
		res[index[0] - 1]++;
	temp = res;
	res = ft_strdup(res);
	free(temp);
	return (res);
}

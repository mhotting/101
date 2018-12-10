/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dtoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/25 10:07:50 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 16:06:50 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

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
		*f = *f - int_part;
		d++;
	}
}

char		*ft_ldtoa(long double f, int prec)
{
	char	*temp;
	char	*res;
	int		index[3];

	index[0] = 0;
	if ((res = ft_strnew(30 + prec)) == NULL)
		return (NULL);
	if ((index[1] = 0) == 0 && f < 0)
		ft_neg(index, &f, res);
	index[2] = (int)f;
	if ((temp = ft_itoa(index[2])) == NULL)
		return (NULL);
	while (index[1] < (int)ft_strlen(temp))
		res[index[0]++] = temp[index[1]++];
	if (prec > 0)
		res[index[0]++] = '.';
	free(temp);
	f -= index[2];
	ft_decimal(res, prec, &f, index);
	if ((int)(f * 10) >= 5)
		res[index[0] - 1]++;
	temp = res;
	res = ft_strdup(res);
	free(temp);
	return (res);
}

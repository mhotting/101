/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dtoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/25 10:07:50 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 15:27:17 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"
#include <stdio.h>

char	*ft_ldtoa(long double f, size_t prec)
{
	int		int_part;
	char	*temp;
	char	*res;
	size_t	index[2];
	size_t	d;

	if ((res = ft_strnew(30)) == NULL)
		return (NULL);
	index[0] = 0;
	if (f < 0)
	{
		res[index[0]++] = '-';
		f *= -1;
	}
	int_part = (int)f;
	temp = ft_itoa(int_part);
	index[1] = 0;
	while (index[1] < ft_strlen(temp))
		res[index[0]++] = temp[index[1]++];
	res[index[0]++] = '.';
	free(temp);
	f -= int_part;
	d = 0;
	while (d < prec)
	{
		f *= 10;
		int_part = (int)f;
		res[index[0]++] = int_part + '0';
		f -= int_part;
		d++;
	}
	if ((int)(f * 10) >= 5)
		res[index[0] - 1]++;
	temp = res;
	res = ft_strdup(res);
	free(temp);
	return (res);
}

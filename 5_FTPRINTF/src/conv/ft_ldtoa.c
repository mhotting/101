/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ldtoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 15:19:14 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/25 10:09:03 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"
#include <stdio.h>

char	*ft_ldtoa(long double f)
{
	int		int_part;
	char	*temp;
	char	*res;
	size_t	i;
	size_t	j;

	if ((res = ft_strnew(30)) == NULL)
		return (NULL);
	i = 0;
	if (f < 0)
	{
		res[i++] = '-';
		f *= -1;
	}
	int_part = (int)f;
	temp = ft_itoa(int_part);
	j = 0;
	while (j < ft_strlen(temp))
		res[i++] = temp[j++];
	res[i++] = '.';
	free(temp);
	while (f != 0.)
	{
		f *= 10;
		int_part = (int)f;
		res[i++] = int_part + '0';
		f -= int_part;
	}
	temp = res;
	res = ft_strdup(res);
	free(temp);
	return (res);
}

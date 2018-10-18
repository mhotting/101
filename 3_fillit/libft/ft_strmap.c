/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:35:37 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 13:46:09 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	size_t	i;

	if (s != NULL)
	{
		res = ft_strnew(ft_strlen(s));
		if (!res)
			return (NULL);
		i = 0;
		while (i < ft_strlen(s))
		{
			res[i] = (*f)(s[i]);
			i++;
		}
		return (res);
	}
	return (NULL);
}

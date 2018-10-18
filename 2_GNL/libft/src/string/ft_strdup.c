/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 13:25:18 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 18:52:28 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*temp;

	if ((temp = ft_strnew(ft_strlen(s))) == NULL)
		return (NULL);
	return (ft_strcpy(temp, s));
}

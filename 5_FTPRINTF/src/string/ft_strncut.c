/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncut.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 14:02:19 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 14:34:38 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

void	ft_strncut(char **str, size_t i, size_t j)
{
	char	*temp;
	char	*res;
	char	*sub1;
	char	*sub2;

	temp = *str;
	sub1 = ft_strsub(*str, 0, i + 1);
	sub2 = ft_strsub(*str, j + 1, (ft_strlen(*str) - (j + 1)));
	*str = ft_strjoin(sub1, sub2);
	free(temp);
	free(sub1);
	free(sub2);
}

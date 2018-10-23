/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/23 14:58:34 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 15:15:51 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_strtabdel(char **tab)
{
	while (*tab)
	{
		ft_strdel(tab);
		tab++;
	}
}

void	ft_lstdelshape(void *s, size_t size)
{
	size_t	i;

	i = size;
	free(s);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   util.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 13:07:39 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 15:14:43 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_lstintdel(void *content, size_t size)
{
	size_t	i;

	i = size;
	if (i == size)
		free(content);
}

void	ft_strtabdel(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_strdel(tab + i);
		i++;
	}
}

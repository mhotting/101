/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/28 03:50:29 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 15:56:57 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

static int	ft_pointadd(t_list **lst, int x, int y, int z)
{
	int		*coord;
	t_list	*cur;

	if (lst == NULL)
		return (-1);
	coord = (int *)ft_memalloc(3 * sizeof(int));
	if (coord == NULL)
		return (-1);
	coord[0] = x;
	coord[1] = y;
	coord[2] = z;
	if ((cur = ft_lstnew(NULL, 0)) == NULL)
		return (-1);
	cur->content = coord;
	ft_lstadd(lst, cur);
	return (1);
}

int		ft_parse(int fd, t_list **lst)
{
	char	*str;
	char	**pts;
	int		x;
	int		y;
	int		ok;

	x = -1;
	while ((ok = get_next_line(fd, &str)) == 1 && (++x) != -2)
	{
		y = -1;
		if ((pts = ft_strsplit(str, ' ')) == NULL)
		{
			free(str);
			return (0);
		}
		while (pts[++y] != NULL)
			ok = ft_pointadd(lst, x, y, ft_atoi(pts[y]));
		ft_strtabdel(pts);
		free(pts);
		free(str);
		if (ok == -1)
			return (0);
	}
	return ((ok >= 0) ? 1 : 0);
}

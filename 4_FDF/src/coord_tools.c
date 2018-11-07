/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   coord_tools.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 21:24:12 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 13:41:31 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_updatecoord(t_list *lst, int h, int l)
{
	t_list	*cur;
	int		xgap;
	int		ygap;

	cur = lst;
	if (l != 1)
		xgap = 900 / (l - 1);
	else
		xgap = 900;
	if (h != 1)
		ygap = 900 / (h - 1);
	else
		ygap = 900;
	while (cur != NULL)
	{
		((int *)(cur->content))[0] += 1300 + ((int *)(cur->content))[0] * xgap;
		((int *)(cur->content))[1] += -200 + ((int *)(cur->content))[1] * ygap;
		cur = cur->next;
	}
}

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

int			ft_parse(int fd, t_list **lst, int *coord)
{
	char	*str;
	char	**pts;
	int		ok;

	coord[0] = -1;
	while ((ok = get_next_line(fd, &str)) == 1 && (++(coord[0])) != -2)
	{
		coord[1] = -1;
		if ((pts = ft_strsplit(str, ' ')) == NULL)
		{
			free(str);
			return (0);
		}
		while (pts[++(coord[1])] != NULL)
			ok = ft_pointadd(lst, coord[1], coord[0],
					-10 * ft_atoi(pts[coord[1]]));
		ft_strtabdel(pts);
		free(pts);
		free(str);
	}
	++(coord[0]);
	ft_lstreverse(lst);
	return ((ok >= 0) ? 1 : 0);
}

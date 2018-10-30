/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   coord_tools.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 21:24:12 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/31 00:01:46 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			***ft_creatematrix(int *size)
{
	int		***matrix;
	int	i;
	int	j;

	if ((matrix = (int ***)ft_memalloc(size[0] * sizeof(int **))) == NULL)
		return (NULL);
	i = -1;
	while (++i < size[0])
	{
		if ((matrix[i] = (int **)ft_memalloc(size[1] * sizeof(int *))) == NULL)
			return (NULL);
	}
	i = -1;
	while (++i < size[0])
	{
		j = -1;
		while (++j < size[1])
		{
			if ((matrix[i][j] = (int *)ft_memalloc(2 * sizeof(int))) == NULL)
				return (NULL);
		}
	}
	return (matrix);
}

void		ft_convertiso(t_list *lst, int *coord)
{
	int	x;
	int	y;
	int	z;

	x = ((int *)(lst->content))[0];
	y = ((int *)(lst->content))[1];
	z = ((int *)(lst->content))[2];
	coord[0] = x * ISO_CST1 - y * ISO_CST2;
	coord[1] = z + (ISO_CST1 /2 * x) + (ISO_CST2 / 2 * y);
}

int			***ft_isomatrix(t_list *lst, int *size)
{
	int		***matrix;
	int	i;
	int	j;

	if ((matrix = ft_creatematrix(size)) == NULL)
		return (NULL);
	i = -1;
	while (++i < size[0])
	{
		j = -1;
		while (++j < size[1])
		{
			ft_convertiso(lst, matrix[i][j]);
			lst = lst->next;
		}
	}
	return (matrix);
}

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
		ygap = 700 / (h - 1);
	else
		ygap = 700;
	while (cur != NULL)
	{
		((int *)(cur->content))[0]+= 1300 + ((int *)(cur->content))[0] * xgap;
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

int		ft_parse(int fd, t_list **lst, int *coord)
{
	char	*str;
	char	**pts;
	int		ok;

	coord[0] = -1;
	while ((ok = get_next_line(fd, &str)) == 1 && (++(coord[0])) != -2)
	{
		if ((coord[1] = -1) && (pts = ft_strsplit(str, ' ')) == NULL)
		{
			free(str);
			return (0);
		}
		while (pts[++(coord[1])] != NULL)
			ok = ft_pointadd(lst, coord[1], coord[0], -15 * ft_atoi(pts[coord[1]]));
		ft_strtabdel(pts);
		free(pts);
		free(str);
	}
	++(coord[0]);
	ft_lstreverse(lst);
	return ((ok >= 0) ? 1 : 0);
}

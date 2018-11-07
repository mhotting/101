/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   matrix_generator.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 12:03:26 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/07 14:38:09 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fdf.h"

static void	ft_isocoord(t_list *lst, int ***matrix, int *size)
{
	t_list	*cur;
	int		i;
	int		j;
	int		*coord;

	cur = lst;
	i = 0;
	while (i < size[0])
	{
		j = 0;
		while (j < size[1])
		{
			coord = (int *)cur->content;
			matrix[i][j][0] = (int)(ISO_CST1 * coord[0] - ISO_CST2 * coord[1]);
			matrix[i][j][1] = (int)(-1 * coord[2] + (ISO_CST1 / 2) * coord[0] +
					(ISO_CST2 / 2) * coord[1]);
			cur = cur->next;
			j++;
		}
		i++;
	}
}

static int	***ft_initmatrix(int *size)
{
	int	i;
	int	j;
	int	***matrix;

	matrix = (int ***)ft_memalloc(size[0] * sizeof(int **));
	if (matrix == NULL)
		return (NULL);
	i = -1;
	while (++i < size[0])
	{
		matrix[i] = (int **)ft_memalloc(size[1] * sizeof(int *));
		if (matrix[i] == NULL)
			exit(0);
	}
	i = -1;
	while (++i < size[0] && (j = -1))
		while (++j < size[1])
		{
			matrix[i][j] = (int *)ft_memalloc(2 * sizeof(int));
			if (matrix[i][j] == NULL)
				exit(0);
		}
	return (matrix);
}

void		ft_isomatrix(t_list *lst, int *size, int ****matrix)
{
	if (*matrix == NULL)
		*matrix = ft_initmatrix(size);
	if (*matrix == NULL)
		return ;
	ft_isocoord(lst, *matrix, size);
}

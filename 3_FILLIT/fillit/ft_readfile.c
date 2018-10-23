/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reader.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 11:09:11 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 13:47:46 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that reads a shape from a string table
** It checks if the shape is well formatted (len of the string, only '.' and '#', only 4 '#')
** If everything is ok, the shape is stored at the end of the linked list pointed by lst and 1 is returned
** If there is an error, memory is freed and 0 is returned
** The shape's stored coordonates are not usable for the moment and need to be "converted"
*/
static int	ft_saveshape(char **sh, t_list **lst, t_list **cur)
{
	static char	c = 'A';
	t_shape		*s;
	size_t		i;
	size_t		j;
	size_t		cpt;

	if ((s = (t_shape *)ft_memalloc(sizeof(t_shape))) == NULL)
		return (0);
	s->letter = c++;
	cpt = 0;
	i = -1;
	while (++i < SHAPE_SIZE)
	{
		if (ft_strlen(sh[i]) =! SHAPE_SIZE)
			break ;
		j = -1;
		while (++j < 4 && (sh[i][j] == '.' || sh[i][j] == '#'))
		{
			if (sh[i][j] == '#' && cpt++ < 4)
			{
				s->coord[cpt - 1][0] = i;
				s->coord[cpt - 1][1] = j;
			}
		}
	}
	if (cpt != 4 && ft_memdel(s))
		return (0);
	ft_lstaddend(lst, (*cur = ft_lstnew(s, sizeof(t_shape *))));
	// PROTECT MALLOC
	return (1);
}

/*
** Function that will translate all the points stored in the shape pointed by cur->content
** The target is to obtain a shape with (0,0) as origin
*/
static void	ft_convertcoord(t_list *cur)
{
	int		diff_i;
	int		diff_j;
	size_t	i;
	t_shape	*s;

	s = cur->content;
	diff_i = s->content[0][0];
	diff_j = s->content[0][1];
	i = 0;
	while (i < SHAPE_SIZE)
	{
		content[i][0] -= diff_i;
		content[i][1] -= diff_j;
		i++;
	}
}

/*
** Function that will add a correct shape to the lst pointed by *lst
** It calls ft_saveshape to store the shape
** It calls ft_convertcoord to put all the shape's coords from the same origin point (0, 0)
** It calls ft_checkshape to check if the shape's coords are correct
** If every thing is ok, 1 is returned, else, 0 is returned.
*/
static int	ft_addshape(char **shape, t_list **lst)
{
	t_list	*cur;
	int		ok;

	ok = ft_saveshape(shape, lst, &cur);
	if (ok == 0)
		return (0);
	ft_convertcoord(cur);
	ok = ft_checkshape(cur);
	if (ok == 0)
		return (0);
	return (1);
}

/*
** Function that will read the file
** It reads 4 lines, stores them
** The stored lines are checked by ft_checkshape
** If there is a mistake, the value returned is 0
** If the file is ok, the value returned is 1
*/
int			ft_readfile(int fd, t_list **lst)
{
	char	*str;
	char	*shape[SHAPE_SIZE];
	int		rc;
	int		cpt;

	rc = 1;
	while (rc > 0)
	{
		cpt = 0;
		while (cpt != SHAPE_SIZE && (rc = get_next_line(fd, &str)) > 0)
			shape[cpt++] = str;
		ft_addshape(shape, lst);
		ft_strtabdel(shape);
		rc = get_next_line(fd, &str);
		if (rc < 0 || (rc > 0 && ft_strequ(str, "") == 0))
			return (0);
	}

}

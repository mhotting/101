/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reader.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 11:09:11 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 20:16:04 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	ft_pushshape(int cpt, t_list **lst, t_list **cur, t_shape **s)
{
	if (cpt != 4)
	{
		ft_memdel((void **)s);
		return (0);
	}
	ft_lstaddend(lst, (*cur = ft_lstnew(NULL, 0)));
	if (*cur == NULL)
		return (0);
	(*cur)->content = *s;
	(*cur)->content_size = sizeof(t_shape *);
	return (1);
}

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
	int			tab[3];

	if ((s = (t_shape *)ft_memalloc(sizeof(t_shape))) == NULL)
		return (0);
	s->letter = c++;
	tab[0] = 0;
	tab[1] = -1;
	while (++(tab[1]) < SHAPE_SIZE && (tab[2] = -1))
	{
		if (ft_strlen(sh[tab[1]]) != 4 && (tab[0] = 1))
			break ;
		while (++(tab[2]) < 4)
		{
			if (sh[tab[1]][tab[2]] != '.' && sh[tab[1]][tab[2]] != '#')
				return (ft_pushshape(0, NULL, NULL, &s));
			if (sh[tab[1]][tab[2]] == '#' && (tab[0])++ < 4)
			{
				s->coord[tab[0] - 1][0] = tab[1];
				s->coord[tab[0] - 1][1] = tab[2];
			}
		}
	}
	return (ft_pushshape(tab[0], lst, cur, &s));
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

	s = (t_shape *)cur->content;
	diff_i = s->coord[0][0];
	diff_j = s->coord[0][1];
	i = 0;
	while (i < SHAPE_SIZE)
	{
		s->coord[i][0] -= diff_i;
		s->coord[i][1] -= diff_j;
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
	char	*shape[SHAPE_SIZE + 1];
	int		rc;
	int		cpt;

	shape[SHAPE_SIZE] = NULL;
	rc = 1;
	while (rc > 0)
	{
		cpt = 0;
		while (cpt != SHAPE_SIZE && (rc = get_next_line(fd, &str)) > 0)
			shape[cpt++] = str;
		if (cpt < SHAPE_SIZE && (rc = -1))
			break ;
		rc = ft_addshape(shape, lst);
		ft_strtabdel(shape);
		if ((cpt < SHAPE_SIZE || rc == 0) && (rc = -1))
			break ;
		rc = get_next_line(fd, &str);
		if (rc < 0 || (rc > 0 && ft_strequ(str, "") == 0))
			rc = -1;
		if (rc > 0)
			free(str);
	}
	return ((rc == -1 || ft_lstlen(*lst) > 26) ? 0 : 1);
}

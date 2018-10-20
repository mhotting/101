/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   reader.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/20 11:09:11 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/20 16:31:08 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that checks if the given shape is well formated
** Then it checks if the shape is part of the "shapes pool"
** If all the test are ok, it adds the shape to the list given as agrument
** and returns 1
** If the shape is not correct it returns 0
*/
static int	ft_checkshape(char **shape, t_list **lst)
{
	return (0);
}

/*
** Function that will read the file
** It reads 4 lines, stores them
** The stored lines are checked by ft_checkshape
** If there is a mistake, the value returned is 0
** If the file is ok, the value returned is 1
*/
static int	ft_readfile(int fd, t_list **lst)
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
		ft_checkshape(shape, lst);
		ft_strtabdel(shape);
		rc = get_next_line(fd, &str);
		if (rc < 0 || (rc > 0 && ft_strequ(str, "") == 0))
			return (0);
	}

}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 16:13:23 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 17:12:22 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		check;
	t_list	*lst;
	t_list	*cur;
	t_shape	*s;
	char	**grid;

	if (argc != 2)
	{
		ft_putendl("usage:\t./fillit file_name");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_puterror());
	lst = NULL;
	check = ft_readfile(fd, &lst);
	close (fd);
	if (check == 0)
	{
		ft_lstdel(&lst, &ft_lstdelshape);
		return (ft_puterror());
	}
	// DEBUG
	cur = lst;
	while (cur != NULL)
	{
		s = cur->content;
		printf("\nMAILLON:\n");
		printf("Letter: %c\n", s->letter);
		printf("Coord1: (%d, %d)\n", s->coord[0][0], s->coord[0][1]);
		printf("Coord2: (%d, %d)\n", s->coord[1][0], s->coord[1][1]);
		printf("Coord3: (%d, %d)\n", s->coord[2][0], s->coord[2][1]);
		printf("Coord4: (%d, %d)\n", s->coord[3][0], s->coord[3][1]);
		cur = cur->next;
	}
	ft_lstdel(&lst, &ft_lstdelshape);


	/*
	grid = ft_solve(lst);
	ft_lstdel(&lst, &ft_lstdelshape);
	ft_display(grid);
	ft_strtabdel(grid);
	*/
	return (0);
}

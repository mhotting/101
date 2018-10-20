/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 16:13:23 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/20 16:20:55 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		check;
	t_list	*lst;
	char	**grid;

	if (argc != 2)
	{
		ft_putendl("usage:\t./fillit file_name");
		return (0);
	}
	if ((fd = open(argv[1])) == -1)
		return (ft_puterror());
	check = ft_readfile(fd, lst);
	close (fd);
	if (check == 0)
		return (ft_puterror());
	grid = ft_solve(lst);
	ft_lstdel(&lst, &ft_lstdelshape);
	ft_display(grid);
	ft_strtabdel(grid);
	return (0);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 16:13:23 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/18 16:38:00 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_putendl("usage:\t./fillit file_name");
		return (0);
	}
	if ((fd = open(argv[1])) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	// reading part
	close (fd);
	// solving part
	// displaying part
	return (0);
}

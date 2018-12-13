/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 14:11:21 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 17:10:50 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <fcntl.h>

int	main(void)
{
	int		cpt1;
	int		cpt2;

	cpt1 = ft_printf("Mon float: %b\n", 1321);
	cpt1 = ft_printf("Mon float: % b\n", 1321);
	cpt2 = printf("NOMBRE: %d\n", 36);
	printf("CPT1 = %d - CPT2 = %d\n", cpt1, cpt2);
	return (0);
}

/*
int	main(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		ft_printf("ERROR - Wrong number of arguments\n");
		return (0);
	}
	fd = open(av[1], O_RDWR);
	if (fd == -1)
	{
		ft_printf("ERROR - File error\n");
		return (0);
	}
	ft_fprintf(fd, "Mon fprintf fonctionne, il merite %d / %d!\n", 10, 10);
	close(fd);
	return (0);
}
*/

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 18:54:47 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 16:17:31 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"
#include <stdio.h>

void		ft_initfrac1(t_bag *ptr_bag)
{
	ptr_bag->color = 0xffffff;
	ptr_bag->col = 0;
	ptr_bag->xmin = -2.1;
	ptr_bag->xmax = 0.6;
	ptr_bag->ymin = -1.2;
	ptr_bag->ymax = 1.2;
	ptr_bag->i_max = 100;
	ptr_bag->lim = 4;
}

static void	ft_init(void *ptr)
{
	t_bag	*ptr_bag;

	ptr_bag = (t_bag *)ptr;
	ptr_bag->mlx = mlx_init();
	ptr_bag->win = mlx_new_window(ptr_bag->mlx,
			WIN_L, WIN_H, "FRACTOL: A WAY TO INFINITY");
	ptr_bag->img = NULL;
	ft_context(ptr, 16777215);
	mlx_key_hook(ptr_bag->win, &ft_keymg, ptr);
	mlx_mouse_hook(ptr_bag->win, &ft_mousemg, ptr);
	mlx_hook(ptr_bag->win, 6, 0, &ft_motionmg, ptr);
	ft_initfrac1(ptr_bag);
}

int			main(int ac, char **av)
{
	int		choice;
	t_bag	bag;
	void	*ptr_bag;

	if (ac != 2)
		return (ft_usage());
	choice = ft_atoi(av[1]);
	if (choice < 1 || choice > TOT_FRAC)
		return (ft_puterror("ERROR - Bad argument\n"));
	ptr_bag = (void *)&bag;
	ft_init(ptr_bag);
	ft_mandelbrot(ptr_bag);
	mlx_loop(bag.mlx);
	return (0);
}

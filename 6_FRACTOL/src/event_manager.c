/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 19:23:43 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 05:25:00 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"
#include <stdio.h>

int	ft_zoom(t_bag *ptr_bag, int button)
{
	int	zoom;

	zoom = (button == 5 ? 1 : -1);
	ptr_bag->xmin += zoom * 0.1;
	ptr_bag->xmax -= zoom * 0.1;
	ptr_bag->ymin += zoom * 0.1;
	ptr_bag->ymax -= zoom * 0.1;
	ptr_bag->iter_max += zoom * 2;
	ft_mandelbrot((void *)ptr_bag);
	return (0);
}

int	ft_editparam(t_bag *ptr_bag, int key)
{
	if (key == 0)
		ptr_bag->iter_max += 5;
	else if (key == 1)
		ptr_bag->iter_max -= 5;
	else if (key == 2)
		ptr_bag->limit += 0.3;
	else
		ptr_bag->limit -= 0.3;
	ft_mandelbrot((void *)ptr_bag);
	return (0);
}

int	ft_motionmg(int x, int y, void *ptr)
{
	t_bag	*ptr_bag;

	ptr_bag = (t_bag *)ptr;
	if (x == 36)
		printf("POS: %d - %d\n", x, y);
	return (0);
}

int	ft_keymg(int key, void *ptr)
{
	t_bag	*ptr_bag;

	ptr_bag = (t_bag *)ptr;
	if (key >= 0 && key <= 3)
		ft_editparam(ptr_bag, key);
	if (key == 53)
		exit(0);
	return (0);
}

int	ft_mousemg(int button, int x, int y, void *param)
{
	t_bag	*ptr_bag;

	printf("COORD: %d -%d\n", x, y);
	ptr_bag = (t_bag *)param;
	if (button == 4 || button == 5)
		ft_zoom(ptr_bag, button);
	return (0);
}

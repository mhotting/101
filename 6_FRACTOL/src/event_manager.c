/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 19:23:43 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 07:29:26 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"
#include <stdio.h>

int	ft_zoom(t_bag *ptr_bag, int button)
{
	int		zoom;
	double	coeff;

	coeff = 0.3;
	zoom = (button == 5 ? 1 : -1);
	ptr_bag->xmin += zoom * coeff;
	ptr_bag->xmax -= zoom * coeff;
	ptr_bag->ymin += zoom * coeff;
	ptr_bag->ymax -= zoom * coeff;
	if (ptr_bag->i_max + zoom != 0)
		ptr_bag->i_max += zoom;
	ft_mandelbrot((void *)ptr_bag);
	return (0);
}

int	ft_editparam(t_bag *ptr_bag, int key)
{
	if (key == 0)
		ptr_bag->i_max += 5;
	else if (key == 1 && ptr_bag->i_max > 5)
		ptr_bag->i_max -= 5;
	else if (key == 2)
		ptr_bag->lim += 0.3;
	else
		ptr_bag->lim -= 0.3;
	ft_mandelbrot((void *)ptr_bag);
	return (0);
}

int	ft_colormg(t_bag *ptr_bag)
{
	ptr_bag->col = 1;
	if (ptr_bag->color == 0xffffff)
		ptr_bag->color = 0xffff00;
	else if (ptr_bag->color == 0xffff00)
		ptr_bag->color = 0x113300;
	else if (ptr_bag->color == 0x113300)
		ptr_bag->color = 0x0000ff;
	else if (ptr_bag->color == 0x0000ff)
		ptr_bag->color = 0xff0000;
	else if (ptr_bag->color == 0xff0000)
		ptr_bag->color = 0x00ff00;
	else if (ptr_bag->color == 0x00ff00)
		ptr_bag->color = 0x551155;
	else if (ptr_bag->color == 0x551155)
		ptr_bag->color = 0x424242;
	else
		ptr_bag->color = 0xffffff;
	ft_mandelbrot((void *)ptr_bag);
	return (0);
}

int	ft_motionmg(int x, int y, void *ptr)
{
	t_bag	*ptr_bag;

	ptr_bag = (t_bag *)ptr;
	if (x == 36 && ptr_bag != NULL)
		printf("POS: %d - %d\n", x, y);
	return (0);
}

int	ft_keymg(int key, void *ptr)
{
	t_bag	*ptr_bag;

	ptr_bag = (t_bag *)ptr;
	if (key >= 0 && key <= 3)
		ft_editparam(ptr_bag, key);
	if (key == 8)
		ft_colormg(ptr_bag);
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

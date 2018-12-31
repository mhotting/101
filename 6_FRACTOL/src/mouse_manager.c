/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/31 02:01:23 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/31 04:45:31 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"
#include <stdio.h>

int	ft_zoom(t_bag *ptr, int button, int x, int y)
{
	double	old_size;

	x -= 400;
	y -= 50;
	old_size = ptr->size;
	if (button == 5)
	{
		ptr->size = ptr->size / 2;
		ptr->zoom = ptr->zoom * 2;
		ptr->posx = ptr->posx + ((double)x / (double)FRAC_L) *
			ptr->size - ptr->size / 2;
		ptr->posy = ptr->posy + ((double)y / (double)FRAC_H) *
			ptr->size - ptr->size / 2;
		ptr->move_value /= 2;
		return (0);
	}
	ptr->size = ptr->size * 2;
	ptr->zoom = ptr->zoom / 2;
	ptr->posx = ptr->posx + ((double)x / (double)FRAC_L) *
		ptr->size - ptr->size / 2;
	ptr->posy = ptr->posy + ((double)y / (double)FRAC_H) *
		ptr->size - ptr->size / 2;
	ptr->move_value *= 2;
	return (0);
}

int	ft_bpress(int button, int x, int y, void *ptr)
{
	t_bag	*ptr_bag;

	ptr_bag = (t_bag *)ptr;
	if (button == 1)
		ptr_bag->edit = 1;
	else if (button == 5 || button == 4)
	{
		ft_zoom(ptr_bag, button, x, y);
		(ptr_bag->ft_frac)((void *)ptr_bag);
	}
	return (0);
}

int	ft_brelease(int button, int x, int y, void *ptr)
{
	t_bag	*ptr_bag;

	if (x || y)
		;
	ptr_bag = (t_bag *)ptr;
	if (button == 1)
		ptr_bag->edit = 0;
	return (0);
}

int	ft_motionmg(int x, int y, void *ptr)
{
	t_bag		*ptr_bag;
	static int	oldx = 0;
	static int	oldy = 0;

	ptr_bag = (t_bag *)ptr;
	if (ptr_bag->edit == 1)
	{
		if (x > oldx)
			ptr_bag->julia_param[0] *= 1.005;
		else if (x < oldx)
			ptr_bag->julia_param[0] /= 1.005;
		if (y > oldy)
			ptr_bag->julia_param[1] *= 1.008;
		else if (y < oldy)
			ptr_bag->julia_param[1] /= 1.008;
		(ptr_bag->ft_frac)((void *)ptr_bag);
	}
	oldx = x;
	oldy = y;
	return (0);
}

int	ft_mousemg(int button, int x, int y, void *param)
{
	t_bag	*ptr_bag;

	ptr_bag = (t_bag *)param;
	if (button == 4 || button == 5)
		ft_zoom(ptr_bag, button, x, y);
	(ptr_bag->ft_frac)((void *)ptr_bag);
	return (0);
}

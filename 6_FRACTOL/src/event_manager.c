/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 19:23:43 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/30 22:39:17 by mhotting    ###    #+. /#+    ###.fr     */
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
	}
	else
	{
		ptr->size = ptr->size * 2;
		ptr->zoom = ptr->zoom / 2;
		ptr->posx = ptr->posx + ((double)x / (double)FRAC_L) *
			ptr->size - ptr->size / 2;
		ptr->posy = ptr->posy + ((double)y / (double)FRAC_H) *
			ptr->size - ptr->size / 2;
	}
	return (0);
}

int	ft_editparam(t_bag *ptr_bag, int key)
{
	if (key == 69)
		ptr_bag->i_max += 5;
	else if (key == 78 && ptr_bag->i_max > 5)
		ptr_bag->i_max -= 5;
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

	printf("KEY: %d\n", key);
	ptr_bag = (t_bag *)ptr;
	if (key == 69 || key == 78)
		ft_editparam(ptr_bag, key);
	else if (key == 15 && ptr_bag->col.mode == 1)
		ft_colormg_reverse(ptr_bag);
	else if (key == 8)
		ft_colormg(ptr_bag);
	else if (key == 46)
		ptr_bag->col.mode = (ptr_bag->col.mode == 1 ? 2 : 1);
	else if (key == 53)
		exit(0);
	(ptr_bag->ft_frac)((void *)ptr_bag);
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

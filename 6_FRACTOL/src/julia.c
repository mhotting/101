/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 01:17:26 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/31 14:57:05 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"
#include <stdio.h>

void		ft_initjulia(t_bag *ptr_bag)
{
	ptr_bag->edit = 0;
	if (ptr_bag->choice == 5)
	{
		ptr_bag->julia_param[0] = 0.281;
		ptr_bag->julia_param[1] = 0.01;
	}
	else if (ptr_bag->choice == 8)
	{
		ptr_bag->julia_param[0] = 0.400;
		ptr_bag->julia_param[1] = 0.60;
	}
	else if (ptr_bag->choice == 9)
	{
		ptr_bag->julia_param[0] = 0.520;
		ptr_bag->julia_param[1] = 0.60;
	}
	ptr_bag->size = 2.4;
	ptr_bag->posx = 0;
	ptr_bag->posy = 0;
	ptr_bag->i_max = 100;
	ptr_bag->lim = 4;
	ptr_bag->zoom = 1;
}

static double	ft_julia_re(t_bag *ptr, double z[2], double c)
{
	if (ptr->choice == 5)
		return (z[0] * z[0] - z[1] * z[1] + c);
	else if (ptr->choice == 8)
		return (z[0] * z[0] * z[0] - 3 * z[0] * z[1] * z[1] + c);
	else if (ptr->choice == 9)
		return (z[0] * z[0] * z[0] * z[0] + z[1] * z[1] * z[1] * z[1] -
				6 * z[0] * z[0] * z[1] * z[1] + c);
	return (0);
}

static double	ft_julia_im(t_bag *ptr, double z1, double temp, double c)
{
	if (ptr->choice == 5)
		return (2 * z1 * temp + c);
	else if (ptr->choice == 8)
		return (-1 * z1 * z1 * z1 + 3 * temp * temp * z1 + c);
	else if (ptr->choice == 9)
		return (4 * temp * temp * temp * z1 - 4 * temp * z1 * z1 * z1 + c);
	return (0);
}
static void	ft_julia_calc(t_bag *ptr, double zoomx, double zoomy)
{
	int		xy[2];
	double	z[2];
	double	temp;
	int		i[2];

	xy[1] = -1;
	i[1] = 0;
	while (++xy[1] < FRAC_H && (xy[0] = -1))
		while (++xy[0] < FRAC_L && (i[0] = -1))
		{
			z[0] = xy[0] / zoomx + ptr->posx - ptr->size / 2;
			z[1] = xy[1] / zoomy + ptr->posy - ptr->size / 2;
			while (++i[0] < ptr->i_max && (z[0] * z[0] + z[1] * z[1] < 4))
			{
				temp = z[0];
				z[0] = ft_julia_re(ptr, z, ptr->julia_param[0]);
				z[1] = ft_julia_im(ptr, z[1], temp, ptr->julia_param[1]);
			}
			temp = i[0] * 1. / ptr->i_max;
			ptr->img[i[1]++] = (ptr->col.mode == 1 ?
			ptr->col.color[(int)(temp * 10)] : (int)(temp * ptr->col.random));
		}
}

void		ft_julia(void *ptr)
{
	t_bag			*ptr_bag;
	double			zoomx;
	double			zoomy;

	ptr_bag = (t_bag *)ptr;
	zoomx = FRAC_L / (ptr_bag->size);
	zoomy = FRAC_H / (ptr_bag->size);
	if (ptr_bag->img_ptr != NULL)
		ft_resetimg(ptr_bag);
	else
	{
		ptr_bag->img_ptr = mlx_new_image(ptr_bag->mlx, FRAC_L, FRAC_H);
		ptr_bag->img = (unsigned int *)mlx_get_data_addr(ptr_bag->img_ptr,
				ptr_bag->trash, (ptr_bag->trash) + 1, (ptr_bag->trash) + 2);
	}
	ft_julia_calc(ptr_bag, zoomx, zoomy);
	mlx_put_image_to_window(ptr_bag->mlx, ptr_bag->win,
			ptr_bag->img_ptr, 400, 50);
}

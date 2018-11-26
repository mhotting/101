/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 01:17:26 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 02:05:44 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void		ft_initjulia(t_bag *ptr_bag)
{
	ptr_bag->color = 0xffffff;
	ptr_bag->col = 0;
	ptr_bag->size = 2.4;
	ptr_bag->posx = 0;
	ptr_bag->posy = 0;
	ptr_bag->i_max = 100;
	ptr_bag->lim = 4;
	ptr_bag->zoom = 1;
}

static void	ft_julia_calc(t_bag *ptr, double zoomx, double zoomy)
{
	int		xy[2];
	double	c[2];
	double	z[2];
	double	temp;
	int		i;

	xy[0] = -1;
	while (++xy[0] < FRAC_L && (xy[1] = -1))
		while (++xy[1] < FRAC_H && (i = -1))
		{
			c[0] = 0.280;
			c[1] = 0.01;
			z[0] = xy[0] / zoomx + ptr->posx - ptr->size / 2;
			z[1] = xy[1] / zoomy + ptr->posy - ptr->size / 2;
			while (++i < ptr->i_max && (z[0] * z[0] + z[1] * z[1] < 4))
			{
				temp = z[0];
				z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
				z[1] = 2 * z[1] * temp + c[1];
			}
			if (ptr->col == 1)
				ptr->img[xy[1] * FRAC_L + xy[0]] = i * ptr->color / ptr->i_max;
			else if (i < ptr->i_max)
				ptr->img[xy[1] * FRAC_L + xy[0]] = 0xffffff;
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

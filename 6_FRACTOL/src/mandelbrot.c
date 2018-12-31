/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 19:11:53 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/31 11:11:10 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void			ft_initmand(t_bag *ptr_bag)
{
	ptr_bag->size = 4;
	ptr_bag->posx = 0;
	ptr_bag->posy = 0;
	ptr_bag->i_max = 100;
	ptr_bag->lim = 4;
	ptr_bag->zoom = 1;
}

static double	ft_mand_re(t_bag *ptr, double z[2])
{
	if (ptr->choice == 1)
		return (z[0] * z[0] - z[1] * z[1]);
	else if (ptr->choice == 2)
		return (z[0] * z[0] * z[0] - 3 * z[0] * z[1] * z[1]);
	else if (ptr->choice == 3)
		return (z[0] * z[0] * z[0] * z[0] + z[1] * z[1] * z[1] * z[1] -
				6 * z[0] * z[0] * z[1] * z[1]);
	else
	{
		return (z[0] * z[0] * z[0] * z[0] * z[0] - 10 * z[0] * z[0] *
				z[0] * z[1] * z[1] + 5 * z[0] * z[1] * z[1] * z[1] * z[1]);
	}
	return (0);
}

static double	ft_mand_im(t_bag *ptr, double z1, double temp)
{
	if (ptr->choice == 1)
		return (2 * z1 * temp);
	else if (ptr->choice == 2)
		return (-1 * z1 * z1 * z1 + 3 * temp * temp * z1);
	else if (ptr->choice == 3)
		return (4 * temp * temp * temp * z1 - 4 * temp * z1 * z1 * z1);
	else
	{
		return (5 * temp * temp * temp * temp * z1 - 10 * temp *
				temp * z1 * z1 * z1 + z1 * z1 * z1 * z1 * z1);
	}
	return (0);
}

static void		ft_mandelbrot_calc(t_bag *ptr, double zoomx, double zoomy)
{
	int		xy[2];
	double	c[2];
	double	z[2];
	double	temp;
	int		i[2];

	xy[1] = -1;
	i[1] = 0;
	while (++xy[1] < FRAC_H && (xy[0] = -1))
		while (++xy[0] < FRAC_L && (i[0] = -1))
		{
			c[0] = xy[0] / zoomx + ptr->posx - ptr->size / 2;
			c[1] = xy[1] / zoomy + ptr->posy - ptr->size / 2;
			z[0] = 0;
			z[1] = 0;
			while (++i[0] < ptr->i_max && (z[0] * z[0] + z[1] * z[1] < 4))
			{
				temp = z[0];
				z[0] = ft_mand_re(ptr, z) + c[0];
				z[1] = ft_mand_im(ptr, z[1], temp) + c[1];
			}
			temp = i[0] * 1. / ptr->i_max;
			ptr->img[i[1]++] = (ptr->col.mode == 1 ?
			ptr->col.color[(int)(temp * 10)] : (int)(temp * ptr->col.random));
		}
}

void			ft_mandelbrot(void *ptr)
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
	ft_mandelbrot_calc(ptr_bag, zoomx, zoomy);
	mlx_put_image_to_window(ptr_bag->mlx, ptr_bag->win,
			ptr_bag->img_ptr, 400, 50);
}

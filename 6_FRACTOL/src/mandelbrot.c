/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 19:11:53 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/25 17:15:28 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

static void	ft_mandelbrot_calc(t_bag *ptr, double zoomx, double zoomy)
{
	int		x;
	int		y;
	double	cr;
	double	ci;
	double	zr;
	double	zi;
	double	temp;
	int		i;

	x = -1;
	while (++x < FRAC_L && (y = -1))
		while (++y < FRAC_H && (i = -1))
		{
			cr = x / zoomx + ptr->xmin;
			ci = y / zoomy + ptr->ymin;
			zr = 0;
			zi = 0;
			while (++i < ptr->i_max && (zr * zr + zi * zi < ptr->lim))
			{
				temp = zr;
				zr = zr * zr - zi * zi + cr;
				zi = 2 * zi * temp + ci;
			}
			if (ptr->col == 1)
				ptr->img[y * FRAC_L + x] = i * ptr->color / ptr->i_max;
			else if (i == ptr->i_max)
				ptr->img[y * FRAC_L + x] = 0xffffff;
		}
}

/*
static void	ft_mandelbrot_calc(t_bag *ptr, double zoomx, double zoomy)
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
			c[0] = xy[0] / zoomx + ptr->xmin;
			c[1] = xy[1] / zoomy + ptr->ymin;
			z[0] = 0;
			z[1] = 0;
			while (++i < ptr->i_max && (z[0] * z[0] + z[1] * z[1] < ptr->lim))
			{
				temp = z[0];
				z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
				z[1] = 2 * z[1] * temp + c[1];
			}
			if (ptr->col == 1)
				ptr->img[xy[1] * FRAC_L + xy[0]] = i * ptr->color / ptr->i_max;
			else if (i == ptr->i_max)
				ptr->img[xy[1] * FRAC_L + xy[0]] = 0xffffff;
		}
}
*/

void		ft_mandelbrot(void *ptr)
{
	t_bag			*ptr_bag;
	double			zoomx;
	double			zoomy;

	ptr_bag = (t_bag *)ptr;
	zoomx = FRAC_L / (ptr_bag->xmax - ptr_bag->xmin);
	zoomy = FRAC_H / (ptr_bag->ymax - ptr_bag->ymin);
	if (ptr_bag->img_ptr != NULL)
		ft_resetimg(ptr_bag);
	else
	{
		ptr_bag->img_ptr = mlx_new_image(ptr_bag->mlx, FRAC_L, FRAC_H);
		ptr_bag->img = (unsigned int *)mlx_get_data_addr(ptr_bag->img_ptr, ptr_bag->trash, (ptr_bag->trash) + 1, (ptr_bag->trash) + 2);
	}
	ft_mandelbrot_calc(ptr_bag, zoomx, zoomy);
	mlx_put_image_to_window(ptr_bag->mlx, ptr_bag->win, ptr_bag->img_ptr, 400, 50);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 19:11:53 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 05:51:17 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

static void	ft_mandelbrot_calc(char *str_img, t_bag *ptr_bag)
{
	double				zoomx, zoomy;
	int					x, y;
	double				cr, ci;
	double				zr, zi;
	double				temp;
	int					i;
	unsigned int		*int_img;

	int_img = (unsigned int *)str_img;
	zoomx = FRAC_L / (ptr_bag->xmax - ptr_bag->xmin);
	zoomy = FRAC_H / (ptr_bag->ymax - ptr_bag->ymin);
	x = 0;
	while (x < FRAC_L)
	{
		y = 0;
		while (y < FRAC_H)
		{
			cr = x / zoomx + ptr_bag->xmin;
			ci = y / zoomy + ptr_bag->ymin;
			zr = 0;
			zi = 0;
			i = 0;
			while (i < ptr_bag->iter_max && (zr * zr + zi * zi < ptr_bag->limit))
			{
				temp = zr;
				zr = zr * zr - zi * zi + cr;
				zi = 2 * zi * temp + ci;
				i++;
			}
			if (ptr_bag->col == 1)
				int_img[y * FRAC_L + x] = i * ptr_bag->color / ptr_bag->iter_max;
			else if (i == ptr_bag->iter_max)
				int_img[y * FRAC_L + x] = 0xffffff;
			y++;
		}
		x++;
	}
}

void		ft_mandelbrot(void *ptr)
{
	t_bag	*ptr_bag;
	char	*str_img;

	ptr_bag = (t_bag *)ptr;
	if (ptr_bag->img != NULL)
		mlx_destroy_image(ptr_bag->mlx, ptr_bag->img);
	ptr_bag->img = mlx_new_image(ptr_bag->mlx, FRAC_L, FRAC_H);
	str_img = mlx_get_data_addr(ptr_bag->img, ptr_bag->trash,
			(ptr_bag->trash) + 1, (ptr_bag->trash) + 2);
	ft_mandelbrot_calc(str_img, ptr_bag);
	mlx_put_image_to_window(ptr_bag->mlx, ptr_bag->win, ptr_bag->img, 400, 50);
}

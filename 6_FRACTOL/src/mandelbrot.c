/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 19:11:53 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 16:17:23 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

static void	ft_mandelbrot_calc(unsigned int *int_img,
		t_bag *ptr, double zoomx, double zoomy)
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
				int_img[xy[1] * FRAC_L + xy[0]] = i * ptr->color / ptr->i_max;
			else if (i == ptr->i_max)
				int_img[xy[1] * FRAC_L + xy[0]] = 0xffffff;
		}
}

void		ft_mandelbrot(void *ptr)
{
	t_bag			*ptr_bag;
	unsigned int	*int_img;
	double			zoomx;
	double			zoomy;

	ptr_bag = (t_bag *)ptr;
	zoomx = FRAC_L / (ptr_bag->xmax - ptr_bag->xmin);
	zoomy = FRAC_H / (ptr_bag->ymax - ptr_bag->ymin);
	if (ptr_bag->img != NULL)
		mlx_destroy_image(ptr_bag->mlx, ptr_bag->img);
	ptr_bag->img = mlx_new_image(ptr_bag->mlx, FRAC_L, FRAC_H);
	int_img = (unsigned int *)mlx_get_data_addr(ptr_bag->img, ptr_bag->trash,
			(ptr_bag->trash) + 1, (ptr_bag->trash) + 2);
	ft_mandelbrot_calc(int_img, ptr_bag, zoomx, zoomy);
	mlx_put_image_to_window(ptr_bag->mlx, ptr_bag->win, ptr_bag->img, 400, 50);
}

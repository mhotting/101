/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandelbrot.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 19:11:53 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/11 19:28:07 by mhotting    ###    #+. /#+    ###.fr     */
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

static double	ft_mand_re(t_bag *ptr, double z[2], double c)
{
	if (ptr->choice == 6 || ptr->choice == 7)
	{
		z[0] = ft_abs(z[0]);
		z[1] = ft_abs(z[1]);
	}
	if (ptr->choice == 1 || ptr->choice == 6)
		return (z[0] * z[0] - z[1] * z[1] + c);
	else if (ptr->choice == 2 || ptr->choice == 7)
		return (z[0] * z[0] * z[0] - 3 * z[0] * z[1] * z[1] + c);
	else if (ptr->choice == 3)
		return (z[0] * z[0] * z[0] * z[0] + z[1] * z[1] * z[1] * z[1] -
				6 * z[0] * z[0] * z[1] * z[1] + c);
	else
	{
		return (z[0] * z[0] * z[0] * z[0] * z[0] - 10 * z[0] * z[0] * z[0] *
				z[1] * z[1] + 5 * z[0] * z[1] * z[1] * z[1] * z[1] + c);
	}
	return (0);
}

static double	ft_mand_im(t_bag *ptr, double z1, double temp, double c)
{
	if (ptr->choice == 6 || ptr->choice == 7)
	{
		z1 = ft_abs(z1);
		temp = ft_abs(temp);
	}
	if (ptr->choice == 1 || ptr->choice == 6)
		return (2 * z1 * temp + c);
	else if (ptr->choice == 2 || ptr->choice == 7)
		return (-1 * z1 * z1 * z1 + 3 * temp * temp * z1 + c);
	else if (ptr->choice == 3)
		return (4 * temp * temp * temp * z1 - 4 * temp * z1 * z1 * z1 + c);
	else
	{
		return (5 * temp * temp * temp * temp * z1 - 10 * temp *
				temp * z1 * z1 * z1 + z1 * z1 * z1 * z1 * z1 + c);
	}
	return (0);
}

void			ft_mandelbrot(t_bag *ptr, double zoomx, double zoomy, int y)
{
	int		x;
	double	c[2];
	double	z[2];
	double	temp;
	int		i[2];

	i[1] = y * FRAC_L;
	x = -1;
	while (++x < FRAC_L && (i[0] = -1))
	{
		c[0] = x / zoomx + ptr->posx - ptr->size / 2;
		c[1] = y / zoomy + ptr->posy - ptr->size / 2;
		z[0] = 0;
		z[1] = 0;
		while (++i[0] < ptr->i_max && (z[0] * z[0] + z[1] * z[1] < 4))
		{
			temp = z[0];
			z[0] = ft_mand_re(ptr, z, c[0]);
			z[1] = ft_mand_im(ptr, z[1], temp, c[1]);
		}
		temp = i[0] * 1. / ptr->i_max;
		ptr->img[i[1]++] = (ptr->col.mode == 1 ?
		ptr->col.color[(int)(temp * 10)] : (int)(temp * ptr->col.random));
	}
}

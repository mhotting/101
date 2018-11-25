/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   context.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 19:32:13 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/25 23:39:36 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

static void	ft_sidelines2(t_bag *ptr, int color)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 3)
	{
		j = 50;
		while (j < 1300)
		{
			mlx_pixel_put(ptr->mlx, ptr->win, i, j, color);
			j++;
		}
		i++;
	}
	i = 1996;
	while (i < 2001)
	{
		j = 50;
		while (j < 1300)
		{
			mlx_pixel_put(ptr->mlx, ptr->win, i, j, color);
			j++;
		}
		i++;
	}
}

static void	ft_sidelines(t_bag *ptr, int color)
{
	size_t	i;
	size_t	j;

	i = 395;
	while (i < 400)
	{
		j = 50;
		while (j < 1300)
		{
			mlx_pixel_put(ptr->mlx, ptr->win, i, j, color);
			j++;
		}
		i++;
	}
	i = 1650;
	while (i < 1655)
	{
		j = 50;
		while (j < 1300)
		{
			mlx_pixel_put(ptr->mlx, ptr->win, i, j, color);
			j++;
		}
		i++;
	}
}

static void	ft_header_footer(t_bag *ptr, int color)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 2001)
	{
		j = 0;
		while (j < 50)
		{
			mlx_pixel_put(ptr->mlx, ptr->win, i, j, color);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 2001)
	{
		j = 1349;
		while (j > 1299)
		{
			mlx_pixel_put(ptr->mlx, ptr->win, i, j, color);
			j--;
		}
		i++;
	}
}

static void	ft_write_header_footer(t_bag *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, 940, 15, 0,
			"FRACTOL: A WAY TO INFINITY");
	mlx_string_put(ptr->mlx, ptr->win, 1800, 1315, 0, "2018 - 101 project");
}

void		ft_context(void *ptr, int color)
{
	t_bag	*ptr_bag;

	ptr_bag = (t_bag *)ptr;
	ft_header_footer(ptr_bag, color);
	ft_sidelines(ptr_bag, color);
	ft_sidelines2(ptr_bag, color);
	ft_write_header_footer(ptr_bag);
}

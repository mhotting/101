/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   context.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 19:32:13 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 19:36:49 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

static void	ft_sidelines(t_bag *ptr, int color)
{
	size_t	i;
	size_t	j;

	i = 245;
	while (i < 250)
	{
		j = 0;
		while (j < 1300)
		{
			mlx_pixel_put(ptr->mlx, ptr->win, i, j, color);
			j++;
		}
		i++;
	}
	i = 2361;
	while (i <= 2366)
	{
		j = 0;
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

	i = 249;
	while (i < 2361)
	{
		j = 95;
		while (j < 100)
		{
			mlx_pixel_put(ptr->mlx, ptr->win, i, j, color);
			j++;
		}
		i++;
	}
	i = 245;
	while (i < 2367)
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

static void	ft_write_header_footer(t_bag *ptr, int color)
{
	mlx_string_put(ptr->mlx, ptr->win, 1140, 40, color,
			"FRACTOL: A WAY TO INFINITY");
	mlx_string_put(ptr->mlx, ptr->win, 2150, 1315, 0, "2018 - 101 project");
}

void		ft_context(void *ptr, int color)
{
	t_bag	*ptr_bag;

	ptr_bag = (t_bag *)ptr;
	ft_header_footer(ptr_bag, color);
	ft_sidelines(ptr_bag, color);
	ft_write_header_footer(ptr_bag, color);
}

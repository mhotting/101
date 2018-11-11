/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   context.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 16:45:35 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/11 17:07:56 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fdf.h"

static void	ft_sidelines(void **ptr, int color)
{
	size_t	i;
	size_t	j;

	i = 195;
	while (i <= 200)
	{
		j = 0;
		while (j < 1300)
		{
			mlx_pixel_put(ptr[0], ptr[1], i, j, color);
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
			mlx_pixel_put(ptr[0], ptr[1], i, j, color);
			j++;
		}
		i++;
	}
}

static void	ft_header_footer(void **ptr, int color)
{
	size_t	i;
	size_t	j;

	i = 199;
	while (i < 2361)
	{
		j = 95;
		while (j < 100)
		{
			mlx_pixel_put(ptr[0], ptr[1], i, j, color);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 2560)
	{
		j = 1349;
		while (j > 1299)
		{
			mlx_pixel_put(ptr[0], ptr[1], i, j, color);
			j--;
		}
		i++;
	}
}

static void	ft_write_header_footer(void **ptr)
{
	mlx_string_put(ptr[0], ptr[1], 1140, 40, 16777215,
			"FDF - Wireframe map displayer");
	mlx_string_put(ptr[0], ptr[1], 2350, 1315, 0, "2018 - 101 project");
}

void		ft_context(void **ptr, int color)
{
	ft_header_footer(ptr, color);
	ft_sidelines(ptr, color);
	ft_write_header_footer(ptr);
}

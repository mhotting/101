/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_line.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/28 01:37:45 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 23:12:35 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_dl1(int *dxy, int *coord, int *inc, void **ptr)
{
	int	i;
	int	cumul;

	cumul = dxy[0] / 2;
	i = 0;
	while (++i <= dxy[0])
	{
		coord[0] += inc[0];
		cumul += dxy[1];
		if (cumul >= dxy[0])
		{
			cumul -= dxy[0];
			coord[1] += inc[1];
		}
		mlx_pixel_put(ptr[0], ptr[1], coord[0], coord[1], 16777215);
	}
}

static void	ft_dl2(int *dxy, int *coord, int *inc, void **ptr)
{
	int	i;
	int	cumul;

	cumul = dxy[1] / 2;
	i = 0;
	while (++i < dxy[1])
	{
		coord[1] += inc[1];
		cumul += dxy[0];
		if (cumul >= dxy[1])
		{
			cumul -= dxy[1];
			coord[0] += inc[0];
		}
		mlx_pixel_put(ptr[0], ptr[1], coord[0], coord[1], 16777215);
	}
}

void		ft_drawline(int *point1, int *point2, void **ptr)
{
	int	dxy[2];
	int	inc[2];
	int coord[2];

	coord[0] = point1[0];
	coord[1] = point1[1];
	dxy[0] = point2[0] - point1[0];
	dxy[1] = point2[1] - point1[1];
	inc[0] = (dxy[0] > 0) ? 1 : -1;
	inc[1] = (dxy[1] > 0) ? 1 : -1;
	dxy[0] = abs(dxy[0]);
	dxy[1] = abs(dxy[1]);
	mlx_pixel_put(ptr[0], ptr[1], coord[0], coord[1], 16777215);
	if (dxy[0] > dxy[1])
		ft_dl1(dxy, coord, inc, ptr);
	else
		ft_dl2(dxy, coord, inc, ptr);
}

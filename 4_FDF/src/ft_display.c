/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_display.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 17:00:38 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/31 00:23:37 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_header_footer(void **ptr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 2560)
	{
		j = 0;
		while (j < 100)
		{
			mlx_pixel_put(ptr[0], ptr[1], i, j, 16777215);
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
			mlx_pixel_put(ptr[0], ptr[1], i, j, 16777215);
			j--;
		}
		i++;
	}
}

void	ft_write_header_footer(void **ptr)
{
	mlx_string_put(ptr[0], ptr[1], 1140, 50, 0,
			"FDF - Wireframe map displayer");
	mlx_string_put(ptr[0], ptr[1], 2350, 1315, 0, "2018 - 101 project");
}

void	ft_dispmatrix(int ***matrix, int *size, void **ptr)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size[0])
	{
		j = -1;
		while (++j < size[1])
		{
			if (i < size[0] - 1)
				ft_drawline(matrix[i][j], matrix[i + 1][j], ptr);
			if (j < size[1] - 1)
				ft_drawline(matrix[i][j], matrix[i][j + 1], ptr);
		}
	}
}

void	ft_display(t_list *lst, int *size)
{
	void	*ptr[2];
	int		***matrix;

	ptr[0] = mlx_init();
	ptr[1] = mlx_new_window(ptr[0], 2560, 1350, "F.D.F -> Fans Domifile Fixe");
	matrix = ft_isomatrix(lst, size);
	ft_dispmatrix(matrix, size, ptr);
	mlx_key_hook(ptr[1], &ft_testkey, ptr);
	ft_header_footer(ptr);
	ft_write_header_footer(ptr);
	mlx_loop(ptr[0]);
}

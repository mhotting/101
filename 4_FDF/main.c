/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/27 20:08:20 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/28 02:03:40 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		ft_testkey(int key, void *param)
{
	printf("Key: %d\n", key);
	if (key == 53)
		exit(0);
	return (0);
}

int	main(void)
{
	void	*ptr[2];
	void	*mlx_ptr;
	void	*win_ptr;
	int		pt1[2], pt2[2], pt3[2], pt4[2], pt5[2], pt6[2], pt7[2], pt8[2];

	pt1[0] = (int)(ISO_CST1 * 900 - ISO_CST2 * 400);
	pt1[1] = (int)(0 + (ISO_CST1 / 2 * 900) + (ISO_CST2 / 2 * 400));
	pt2[0] = (int)(ISO_CST1 * 1100 - ISO_CST2 * 400);
	pt2[1] = (int)(0 + (ISO_CST1 / 2 * 1100) + (ISO_CST2 / 2 * 400));
	pt3[0] = (int)(ISO_CST1 * 900 - ISO_CST2 * 600);
	pt3[1] = (int)(0 + (ISO_CST1 / 2 * 900) + (ISO_CST2 / 2 * 600));
	pt4[0] = (int)(ISO_CST1 * 1100 - ISO_CST2 * 600);
	pt4[1] = (int)(0 + (ISO_CST1 / 2 * 1100) + (ISO_CST2 / 2 * 600));
	pt5[0] = (int)(ISO_CST1 * 900 - ISO_CST2 * 400);
	pt5[1] = (int)(200 + (ISO_CST1 / 2 * 900) + (ISO_CST2 / 2 * 400));
	pt6[0] = (int)(ISO_CST1 * 1100 - ISO_CST2 * 400);
	pt6[1] = (int)(200 + (ISO_CST1 / 2 * 1100) + (ISO_CST2 / 2 * 400));
	pt7[0] = (int)(ISO_CST1 * 900 - ISO_CST2 * 600);
	pt7[1] = (int)(200 + (ISO_CST1 / 2 * 900) + (ISO_CST2 / 2 * 600));
	pt8[0] = (int)(ISO_CST1 * 1100 - ISO_CST2 * 600);
	pt8[1] = (int)(200 + (ISO_CST1 / 2 * 1100) + (ISO_CST2 / 2 * 600));

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2000, 1000, "TEST WINDOW");
	ptr[0] = mlx_ptr;
	ptr[1] = win_ptr;
	mlx_key_hook(win_ptr, &ft_testkey, 0);
	ft_drawline(pt1, pt2, ptr);
	ft_drawline(pt1, pt3, ptr);
	ft_drawline(pt1, pt5, ptr);
	ft_drawline(pt2, pt4, ptr);
	ft_drawline(pt2, pt6, ptr);
	ft_drawline(pt3, pt4, ptr);
	ft_drawline(pt3, pt7, ptr);
	ft_drawline(pt4, pt8, ptr);
	ft_drawline(pt5, pt6, ptr);
	ft_drawline(pt5, pt7, ptr);
	ft_drawline(pt6, pt8, ptr);
	ft_drawline(pt7, pt8, ptr);
	mlx_loop(mlx_ptr);
	return (0);
}

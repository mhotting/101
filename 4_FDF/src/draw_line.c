/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw_line.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/28 01:37:45 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/09 19:41:37 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

static char	ft_hextochar(char a, char b)
{
	char	c1;
	char	c2;

	if (a >= 0 && a <= 9)
		c1 = a - '0';
	else
		c1 = a - 'a' + 10;
	if (b >= 0 && b <= 9)
		c2 = b - '0';
	else
		c2 = b - 'a' + 10;
	return (16 * c1 + c2);
}

static void	ft_putpixelstr(int x, int y, int color, char *img_str)
{
	char	*color_hex;
	char	sub[3];
	int		num;

	num = y * 2160 * 4 + 4 * x;
	if (num > 0 && num < (2160 * 4 * 1200) && x < 2160 && x > 0)
	{
		sub[2] = '\0';
		color_hex = ft_itoabase(color, 16);
		sub[0] = color_hex[0];
		sub[1] = color_hex[1];
		img_str[num] = ft_hextochar(sub[0], sub[1]);
		sub[0] = color_hex[2];
		sub[1] = color_hex[3];
		img_str[num + 1] = ft_hextochar(sub[0], sub[1]);
		sub[0] = color_hex[4];
		sub[1] = color_hex[5];
		img_str[num + 2] = ft_hextochar(sub[0], sub[1]);
	}
}

static void	ft_dl1(int *dxy, int *coord, int *inc, char *img_str)
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
		ft_putpixelstr(coord[0], coord[1], 16777215, img_str);
	}
}

static void	ft_dl2(int *dxy, int *coord, int *inc, char *img_str)
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
		ft_putpixelstr(coord[0], coord[1], 16777215, img_str);
	}
}

void		ft_drawline(int *point1, int *point2, char *img_str)
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
	ft_putpixelstr(coord[0], coord[1], 16777215, img_str);
	if (dxy[0] > dxy[1])
		ft_dl1(dxy, coord, inc, img_str);
	else
		ft_dl2(dxy, coord, inc, img_str);
}
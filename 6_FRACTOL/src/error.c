/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 19:33:33 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/31 10:47:54 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_usage(void)
{
	ft_putstr("usage:");
	ft_putendl("\t./fractol [1 | 2 | 3 | 4 | 5]");
	ft_putendl("  - 1: Madelbrot set");
	ft_putendl("  - 2: Mandelbrot three heads");
	ft_putendl("  - 3: Mandelbrot four heads");
	ft_putendl("  - 4: Mandelbrot five heads");
	ft_putendl("  - 5: Julia set");
	return (0);
}

int	ft_puterror(char *str)
{
	ft_putstr(str);
	return (ft_usage());
}

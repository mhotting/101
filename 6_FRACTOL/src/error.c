/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 19:33:33 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 19:50:58 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	ft_usage(void)
{
	ft_putstr("usage:");
	ft_putendl("\t./fractol [1 | 2 | 3]");
	ft_putendl("  - 1: Madelbrot set");
	ft_putendl("  - 2: Julia set");
	ft_putendl("  - 3: Unknown set");
	return (0);
}

int	ft_puterror(char *str)
{
	ft_putstr(str);
	return (ft_usage());
}

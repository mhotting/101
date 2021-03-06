/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rush01.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jde-mour <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/08 13:39:02 by jde-mour     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/21 18:33:11 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/my.h"

void	rush(int x, int y)
{
	int cptl;

	if (x <= 0 || y <= 0)
		return ;
	cptl = 0;
	if (y == 1)
	{
		ft_print_line(x, '/', '*', '\\');
		return ;
	}
	while (cptl < y)
	{
		if (cptl == 0)
			ft_print_line(x, '/', '*', '\\');
		else if (cptl == (y - 1))
			ft_print_line(x, '\\', '*', '/');
		else
			ft_print_line(x, '*', ' ', '*');
		++cptl;
	}
}

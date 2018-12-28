/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 10:50:05 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 11:18:00 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

void	ft_initcol(t_bag *ptr)
{
	(ptr->color[0]).colint = 0;
	(ptr->color[1]).colint = 0;
	(ptr->color[2]).colint = 0;
	(ptr->color[3]).colint = 0;
	(ptr->color[4]).colint = 0;
	(ptr->color[5]).colint = 0;
	(ptr->color[6]).colint = 0;
	(ptr->color[7]).colint = 0;
	(ptr->color[8]).colint = 0;
	(ptr->color[9]).colint = 0xFFFFFF;
}

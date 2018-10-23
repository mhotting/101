/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   errors.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 16:18:54 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 14:56:15 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_printfusage(void)
{
	ft_putstr("usage:\t");
	ft_putendl("./fillit -filename");
}

int		ft_puterror(void)
{
	ft_putendl("error");
	return (0);
}

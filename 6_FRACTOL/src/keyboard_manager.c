/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   keyboard_manager.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/31 02:00:52 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/14 12:21:36 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"
#include <stdio.h>

int	ft_move(t_bag *ptr, int key)
{
	if (key == 126)
		ptr->posy += ptr->move_value;
	else if (key == 125)
		ptr->posy -= ptr->move_value;
	else if (key == 123)
		ptr->posx += ptr->move_value;
	else
		ptr->posx -= ptr->move_value;
	return (0);
}

int	ft_editparam(t_bag *ptr_bag, int key)
{
	if (key == 69)
		ptr_bag->i_max += 5;
	else if (key == 78 && ptr_bag->i_max > 5)
		ptr_bag->i_max -= 5;
	return (0);
}

int	ft_keymg(int key, void *ptr)
{
	t_bag	*ptr_bag;

	printf("KEY: %d\n", key);
	ptr_bag = (t_bag *)ptr;
	if (key == 69 || key == 78)
		ft_editparam(ptr_bag, key);
	else if (key >= 123 && key <= 126)
		ft_move(ptr_bag, key);
	else if (key == 15 && ptr_bag->col.mode == 1)
		ft_colormg_reverse(ptr_bag);
	else if (key == 8)
		ft_colormg(ptr_bag);
	else if (key == 46)
		ptr_bag->col.mode = (ptr_bag->col.mode == 1 ? 2 : 1);
	else if (key == 82)
	{
		ft_reinit(ptr_bag, ptr_bag->choice);
		ft_initcol(ptr_bag);
	}
	else if (key == 53)
		exit(0);
	ft_sync_frac(ptr);
	return (0);
}

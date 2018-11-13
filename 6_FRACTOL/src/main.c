/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 18:54:47 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 19:31:54 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../includes/fractol.h"

int	main(void)
{
	t_bag	bag;
	void	*ptr_bag;

	ptr_bag = (void *)&bag;
	bag.mlx = mlx_init();
	bag.win = mlx_new_window(bag.mlx, 2560, 1350, "FRACTOL: A WAY TO INFINITY");
	ft_context(ptr_bag, 16777215);
	mlx_key_hook(bag.win, &ft_keymg, ptr_bag);
	mlx_loop(bag.mlx);
	return (0);
}

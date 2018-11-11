/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 18:20:58 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/11 16:14:16 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int	ft_keymanager(int key, void *param)
{
	void	**ptr;

	ptr = (void **)param;
	printf("Key: %d\n", key);
	if (key == 53)
		exit(0);
	if (key >= 123 && key <= 126)
		ft_slide(key, ptr);
	if (key == 69 || key == 78)
		ft_editheight(key, ptr);
	if (key == 8)
		ft_changecolor(ptr);
	return (0);
}

int	ft_mousemanager(int mouse, int x, int y, void *param)
{
	void	**ptr;

	ptr = (void **)param;
	printf("Mouse: %d, position: (%d, %d)\n", mouse, x, y);
	if (mouse == 1 || mouse == 2)
		ft_zoom(mouse, ptr);
	return (0);
}

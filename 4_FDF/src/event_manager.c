/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event_manager.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/30 18:20:58 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 20:20:38 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int	ft_testkey(int key, void *param)
{
	param = NULL;
	printf("Key: %d\n", key);
	if (key == 53)
		exit(0);
	return (0);
}

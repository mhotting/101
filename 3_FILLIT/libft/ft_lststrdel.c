/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lststrdel.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 13:57:48 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 14:09:35 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdio.h>

void	ft_lststrdel(void *ptr, size_t size)
{
	size_t	i;

	i = size;
	i++;
	free(ptr);
}

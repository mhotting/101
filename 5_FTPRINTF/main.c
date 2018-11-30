/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 14:11:21 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 16:56:25 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	int	cpt1;
	int	cpt2;

	i = -34;
	cpt1 = ft_printf("Voici un nombre: %5c\n", '\0');
	cpt2 = printf("Voici un nombre: %5c\n", '\0');
	printf("CPT1 = %d - CPT2 = %d\n", cpt1, cpt2);
	return (0);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 14:11:21 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 15:05:58 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		cpt1;
	int		cpt2;

	cpt1 = ft_printf("Voici une chaine: %x %hx %hhx\n", -42, -42, -42);
	cpt2 = printf("Voici une chaine: %x %hx %hhx\n", -42, -42, -42);
	printf("CPT1 = %d - CPT2 = %d\n", cpt1, cpt2);
	return (0);
}

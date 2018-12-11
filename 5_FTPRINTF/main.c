/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 14:11:21 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 21:34:29 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

int	main(void)
{
	int		cpt1;
	int		cpt2;

	cpt1 = ft_printf("Mon float: %.50Lf\n", 50.L);
	cpt2 = printf("Mon float: %.50Lf\n", 50.L);
	printf("CPT1 = %d - CPT2 = %d\n", cpt1, cpt2);
	return (0);
}

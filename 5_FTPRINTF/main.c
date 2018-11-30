/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 14:11:21 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 21:58:22 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	int		cpt1;
	int		cpt2;
	char	*s;

	i = -34;
	s = ft_strdup("BONJOUR");
	if (s == NULL)
		return (0);
	cpt1 = ft_printf("Voici une chaine: %#o\n", 1);
	cpt2 = printf("Voici une chaine: %#o\n", 1);
	printf("CPT1 = %d - CPT2 = %d\n", cpt1, cpt2);
	free(s);
	return (0);
}

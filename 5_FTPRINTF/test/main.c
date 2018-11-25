/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 15:32:01 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/25 13:21:17 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		i;
	/*
	char	*res;

	res = (char *)malloc(8 * sizeof(char));
	if (res == NULL)
		exit(0);
	res[0] = 'B';
	res[1] = 'o';
	res[2] = 'n';
	res[3] = 'j';
	res[4] = 'o';
	res[5] = 'u';
	res[6] = 'r';
	res[7] = '\0';
	i = printf("%llu\n", (unsigned long long int)res);
	i = printf("%p\n", res);
	*/
	i = printf("Print: %x\n", 213);
	printf("Returned value: %d\n", i);
	//free(res);
	return (0);
}

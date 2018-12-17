/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 14:11:21 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 18:06:44 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <fcntl.h>

int	main(void)
{
	/*
	int 			c1;
	int				c2;
	int				test_int;
	long int		test_lint;
	long long int	test_llint;
	float			test_f;
	double			test_d;
	long double		test_ld;

	// TESTS D'ENTIERS
	ft_printf("********************\n");
	ft_printf("*      ENTIERS     *\n");
	ft_printf("********************\n\n");
	// 1
	test_int = 12;
	c1 = ft_printf("ft_printf: %d\n", test_int);
	c2 = printf("printf   : %d\n", test_int);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 2
	test_int = -36;
	c1 = ft_printf("ft_printf: %d\n", test_int);
	c2 = printf("printf   : %d\n", test_int);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 3
	test_int = 12;
	c1 = ft_printf("ft_printf: %10d\n", test_int);
	c2 = printf("printf   : %10d\n", test_int);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 4
	test_int = 12;
	c1 = ft_printf("ft_printf: %.10d\n", test_int);
	c2 = printf("printf   : %.10d\n", test_int);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 5
	test_int = 12;
	c1 = ft_printf("ft_printf: %-10d\n", test_int);
	c2 = printf("printf   : %-10d\n", test_int);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 6
	test_int = 12;
	c1 = ft_printf("ft_printf: %+10d\n", test_int);
	c2 = printf("printf   : %+10d\n", test_int);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 7
	test_int = 12;
	c1 = ft_printf("ft_printf: % 5d\n", test_int);
	c2 = printf("printf   : % 5d\n", test_int);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 8
	test_int = -2147483648;
	c1 = ft_printf("ft_printf: %i\n", test_int);
	c2 = printf("printf   : %i\n", test_int);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');

	// 9
	test_lint = LONG_MIN;
	c1 = ft_printf("ft_printf: %ld\n", test_lint);
	c2 = printf("printf   : %ld\n", test_lint);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 10
	test_lint = LONG_MAX;
	c1 = ft_printf("ft_printf: %ld\n", test_lint);
	c2 = printf("printf   : %ld\n", test_lint);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 11
	test_llint = LLONG_MIN;
	c1 = ft_printf("ft_printf: %lld\n", test_llint);
	c2 = printf("printf   : %lld\n", test_llint);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 12
	test_llint = LLONG_MAX;
	c1 = ft_printf("ft_printf: %lld\n", test_llint);
	c2 = printf("printf   : %lld\n", test_llint);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 13
	test_int = 12;
	c1 = ft_printf("ft_printf: %o\n", test_int);
	c2 = printf("printf   : %o\n", test_int);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 14
	test_int = 36;
	c1 = ft_printf("ft_printf: %x\n", test_int);
	c2 = printf("printf   : %x\n", test_int);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 15
	test_int = 12;
	c1 = ft_printf("ft_printf: %10x\n", test_int);
	c2 = printf("printf   : %10x\n", test_int);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 16
	test_int = 12;
	c1 = ft_printf("ft_printf: %.10o\n", test_int);
	c2 = printf("printf   : %.10o\n", test_int);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 17
	test_int = 12;
	c1 = ft_printf("ft_printf: %-10X\n", test_int);
	c2 = printf("printf   : %-10X\n", test_int);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 18
	test_int = 12;
	c1 = ft_printf("ft_printf: %10o\n", test_int);
	c2 = printf("printf   : %10o\n", test_int);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 19
	test_int = 12;
	c1 = ft_printf("ft_printf: %5x\n", test_int);
	c2 = printf("printf   : %5x\n", test_int);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 20
	test_lint = LONG_MIN;
	c1 = ft_printf("ft_printf: %lx\n", test_lint);
	c2 = printf("printf   : %lx\n", test_lint);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 21
	test_lint = LONG_MAX;
	c1 = ft_printf("ft_printf: %lo\n", test_lint);
	c2 = printf("printf   : %lo\n", test_lint);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 22
	test_llint = LLONG_MIN;
	c1 = ft_printf("ft_printf: %llX\n", test_llint);
	c2 = printf("printf   : %llX\n", test_llint);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
	
	// 23
	test_llint = LLONG_MAX;
	c1 = ft_printf("ft_printf: %llx\n", test_llint);
	c2 = printf("printf   : %llx\n", test_llint);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');

	// TESTS DE FLOAT
	ft_printf("********************\n");
	ft_printf("*      DOUBLE      *\n");
	ft_printf("********************\n\n");

	// 1
	test_f = 36.5;
	c1 = ft_printf("ft_printf: %f\n", test_f);
	c2 = printf("printf   : %f\n", test_f);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');

	// 2
	test_f = FLT_MIN;
	c1 = ft_printf("ft_printf: %f\n", test_f);
	c2 = printf("printf   : %f\n", test_f);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');

	// 3
	test_f = FLT_MAX;
	c1 = ft_printf("ft_printf: %f\n", test_f);
	c2 = printf("printf   : %f\n", test_f);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');

	// 4
	test_f = 27.45555555;
	c1 = ft_printf("ft_printf: %.2f\n", test_f);
	c2 = printf("printf   : %.2f\n", test_f);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');

	// 1
	test_f = 27.455;
	c1 = ft_printf("ft_printf: %.2f\n", test_f);
	c2 = printf("printf   : %.2f\n", test_f);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');

	// 1
	test_f = 1.99;
	c1 = ft_printf("ft_printf: %.f\n", test_f);
	c2 = printf("printf   : %.f\n", test_f);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');

	// 1
	test_d = DBL_MAX;
	c1 = ft_printf("ft_printf: %lf\n", test_d);
	c2 = printf("printf   : %lf\n", test_d);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');

	// 1
	test_ld = LDBL_MAX;
	c1 = ft_printf("ft_printf: %Lf\n", test_ld);
	c2 = printf("printf   : %Lf\n", test_ld);
	ft_printf("c1: %d - c2: %d\n", c1, c2);
	ft_printf("(APPUYER SUR ENTREE...)\n");
	while (getchar() != '\n');
*/
	float	f;

	f = FLT_MAX;
	ft_printf("%f\n", f);
	printf("%f\n", f);
}

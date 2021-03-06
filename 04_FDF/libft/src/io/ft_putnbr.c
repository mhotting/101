/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 10:34:40 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 10:48:07 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

static long	eval_mul(long num)
{
	long	mul;

	mul = 1;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		mul *= 10;
		num /= 10;
	}
	return (mul / 10);
}

void		ft_putnbr(int n)
{
	long	num;
	long	mul;

	num = (long)n;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	mul = eval_mul(num);
	while (mul != 0)
	{
		ft_putchar((int)(num / mul) + '0');
		num %= mul;
		mul /= 10;
	}
}

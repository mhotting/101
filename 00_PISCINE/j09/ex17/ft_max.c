/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_max.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/13 16:02:51 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/13 16:18:33 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_max(int *tab, int length)
{
	int i;
	int max;

	if (length == 0)
		return (0);
	max = tab[0];
	i = 1;
	while (i < length)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}
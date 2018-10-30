/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/27 20:08:20 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 17:06:17 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	ft_debuglst(t_list	*lst)
{
	size_t	i;

	i = 0;
	while (lst != NULL)
	{
		printf("MAILLON %zu: (%d, %d, %d)\n", i, ((int *)lst->content)[0], ((int *)lst->content)[1], ((int *)lst->content)[2]);
		i++;
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_list	*lst;
	int		ok;

	if (argc != 2)
		return (ft_usage());
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_puterror("ERROR - File cannot be read\n"));
	lst = NULL;
	if ((ok = ft_parse(fd, &lst)) == 0)
	{
		ft_lstdel(&lst, &ft_lstintdel);
		ft_puterror("ERROR - Impossible to extract data from file\n");
	}
	ft_debuglst(lst);
	ft_display(lst);
	ft_lstdel(&lst, &ft_lstintdel);
	/*
	ptr[0] = mlx_init();
	ptr[1] = mlx_new_window(ptr[0], 2600, 1350, "Fans Domifile Fixe");
	mlx_key_hook(ptr[1], &ft_testkey, ptr);
	mlx_loop(ptr[0]);
	*/
	return (0);
}

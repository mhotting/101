/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/28 03:50:29 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/28 04:42:04 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_parse(int fd, t_point **lst)
{
	t_point	*cur;
	char	*str;
	char	**pts;
	int		x;
	int		y;

	x = -1;
	while (get_next_line(fd, &str) == 1 && ++x)
	{
		y = -1;
		if ((pts = ft_strsplit(str, ' ')) == NULL)
		{
			free(str);
			return ;
		}
		while (pts[++y] != NULL)
			ft_pointadd(lst, x, y, ft_atoi(pts[y]));
		ft_strtabdel(pts);
		free(pts);
		free(str);
	}
	ft_pointreverse(lst);
}

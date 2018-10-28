/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/28 01:38:57 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/28 04:28:01 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <math.h>
# define ISO_CST1 0.75
# define ISO_CST2 0.75

typedef struct	s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
}				t_point;

void	ft_drawline(int *point1, int *point2, void **ptr);

#endif

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/18 14:55:32 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 13:32:01 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./../libft/includes/libft.h"
# define SHAPE_SIZE 4

typedef struct	s_shape
{
	char	letter;
	int		coord[SHAPE_SIZE][2];
}				t_shape;

int	ft_readfile(int fd, t_list **lst);
int	ft_checkshape(t_list *cur);

#endif

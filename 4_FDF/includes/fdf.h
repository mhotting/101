/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/28 01:38:57 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/30 17:10:59 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "./../minilibx/mlx.h"
# include "./../libft/includes/libft.h"
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define ISO_CST1 0.75
# define ISO_CST2 0.75

void	ft_display(t_list *lst);
void	ft_drawline(int *point1, int *point2, void **ptr);
int		ft_testkey(int key, void *param);
int		ft_parse(int fd, t_list **lst);
void	ft_strtabdel(char **tab);
void	ft_lstintdel(void *content, size_t size);
int		ft_usage(void);
int		ft_puterror(char *str);

#endif

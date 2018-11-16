/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 18:56:35 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 05:49:22 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define WIN_L		2560
# define WIN_H		1350
# define FRAC_L		1960
# define FRAC_H		1250
# define TOT_FRAC	3

typedef struct	s_bag
{
	void	*mlx;
	void	*win;
	void	*img;
	int		trash[3];
	int		iter_max;
	double	limit;
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	int		color;
	char	col;
}				t_bag;

/*
**	ERROR FUNCTIONS
*/
int				ft_usage(void);
int				ft_puterror(char *str);

/*
**	EVENT MANAGEMENT
*/
int				ft_keymg(int key, void *ptr);
int				ft_mousemg(int button, int x, int y, void *param);
int				ft_motionmg(int x, int y, void *ptr);

/*
**	FRACTAL FUNCTIONS
*/
void			ft_mandelbrot(void *ptr);

/*
**	VARIOUS FUNCTIONS
*/
void			ft_context(void *ptr, int color);

#endif

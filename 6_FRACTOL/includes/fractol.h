/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 18:56:35 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/30 22:40:12 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <time.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# define WIN_L		2000
# define WIN_H		1350
# define FRAC_L		1250
# define FRAC_H		1250
# define TOT_FRAC	3
# define COL_RANGE	6

typedef struct	s_col
{
	int	color[11];
	int	mode;
	int	range;
	int	random;
}				t_col;

typedef struct	s_bag
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	unsigned int	*img;
	int				trash[3];
	int				i_max;
	double			lim;
	double			size;
	double			posx;
	double			posy;
	t_col			col;
	double			zoom;
	void			(*ft_init)(struct s_bag *);
	void			(*ft_frac)(void *);
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
void			ft_initmand(t_bag *ptr);
void			ft_julia(void *ptr);
void			ft_initjulia(t_bag *ptr);

/*
**	VARIOUS FUNCTIONS
*/
void			ft_context(void *ptr, int color);
void			ft_resetimg(t_bag *ptr);

/*
**	COLOR FUNCTIONS
*/
void			ft_initcol(t_bag *ptr);
void			ft_lblue(t_bag *ptr);
void			ft_lgreen(t_bag *ptr);
void			ft_red(t_bag *ptr);
void			ft_brown(t_bag *ptr);
void			ft_yellow(t_bag *ptr);
void			ft_teal(t_bag *ptr);
int				ft_colormg(t_bag *ptr_bag);
int				ft_colormg_reverse(t_bag *ptr_bag);

#endif

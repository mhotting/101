/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 17:54:35 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/30 16:26:45 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef struct	s_attibutes
{
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			longd;
	int			prec;
	int			width;
	int			opt1;
	int			opt2;
	int			opt3;
	int			opt4;
	int			opt5;
}				t_attributes;
typedef char *(*t_pf_func)(char *, va_list *, t_attributes *);
typedef struct	s_conf
{
	char		*str;
	t_pf_func	func;
}				t_conv;

/*
** Printf function and attributes
*/
int				ft_printf(const char *format,
		...) __attribute__((format(printf,1,2)));
size_t			ft_putstr_pf(char *str);
void			ft_init_attributes(t_attributes *ptr);
void			ft_eval_attributes(t_attributes *ptr, char *sub);
void			ft_enhance_left(char **res, char c, int len);
void			ft_enhance_right(char **res, char c, int len);
void			ft_intadjust(char *res, t_attributes *att);
void			ft_delzero(char **res);

/*
** Extraction functions
*/
char			*pf_int_arg(char *sub, va_list *ap, t_attributes *att);
char			*pf_c_arg(char *sub, va_list *ap, t_attributes *att);
char			*pf_s_arg(char *sub, va_list *ap, t_attributes *att);
char			*pf_p_arg(char *sub, va_list *ap, t_attributes *att);
char			*pf_f_arg(char *sub, va_list *ap, t_attributes *att);
char			*pf_pc_arg(char *sub, va_list *ap, t_attributes *att);

#endif

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 17:54:35 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/23 19:46:44 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef char *(*t_pf_func)(char *, va_list);
typedef struct	s_conf
{
	char		*str;
	t_pf_func	func;
}				t_conv;

int				ft_printf(const char *format,
		...) __attribute__((format(printf,1,2)));
char			*pf_int_arg(char *sub, va_list ap);
char			*pf_c_arg(char *sub, va_list ap);
char			*pf_s_arg(char *sub, va_list ap);
char			*pf_p_arg(char *sub, va_list ap);
char			*pf_f_arg(char *sub, va_list ap);
char			*pf_pc_arg(char *sub, va_list ap);

#endif

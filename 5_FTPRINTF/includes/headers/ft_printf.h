/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 17:54:35 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/20 19:37:11 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef			char *(*pf_func)(char *, va_list *);
typedef struct	s_conf
{
	char	*str;
	pf_func	func;
}				t_conv;

int				ft_printf(const char *format, ...);

#endif

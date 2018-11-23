/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 14:02:32 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/23 20:16:11 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

static const t_conv	g_conv[] = {
	{ "diouxX", pf_int_arg },
	{ "c", pf_c_arg },
	{ "s", pf_s_arg },
	{ "p", pf_p_arg },
	{ "f", pf_f_arg },
	{ "%", pf_pc_arg }
};

static char			*ft_extract(char **str, size_t i)
{
	size_t	j;
	char	*sub;

	j = i + 1;
	while ((*str)[j] != '\0' && ft_charinstr((*str)[j], "diouxXcspf%") == 0)
		j++;
	if ((*str)[j] == '\0')
		return (NULL);
	sub = ft_strsub(*str, i, (j - i + 1));
	if (sub == NULL)
		return (NULL);
	ft_strncut(str, i, j);
	return (sub);
}

static void			ft_replace(char **str, size_t i, char *res)
{
	char	*final;

	final = ft_strnew(ft_strlen(*str) + ft_strlen(res) - 1);
	ft_strncpy(final, *str, i);
	ft_strncpy(final + i, res, ft_strlen(res));
	ft_strncpy(final + i + ft_strlen(res), *str + i + 1, ft_strlen(*str) - i);
	free(*str);
	*str = final;
}

static t_pf_func	ft_select_func(char *sub)
{
	size_t	i;

	i = 0;
	while (i < 6)
	{
		if (ft_charinstr(sub[ft_strlen(sub) - 1], g_conv[i].str) == 1)
			return (g_conv[i].func);
		i++;
	}
	return (NULL);
}

static void			ft_dispatch(char **str, size_t i, va_list ap)
{
	char		*sub;
	char		*res;
	t_pf_func	f;

	sub = ft_extract(str, i);
	if (sub == NULL)
		return ;
	f = ft_select_func(sub);
	if (*f == NULL)
		return ;
	res = (*f)(sub, ap);
	ft_replace(str, i, res);
	free(res);
	free(sub);
}

int					ft_printf(const char *format, ...)
{
	char	*str;
	va_list	ap;
	int		len_ret;
	size_t	i;

	if (format == NULL)
		return (0);
	str = ft_strdup(format);
	va_start(ap, format);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ft_dispatch(&str, i, ap);
		i++;
	}
	ft_putstr(str);
	va_end(ap);
	len_ret = (int)ft_strlen(str);
	free(str);
	return (len_ret);
}

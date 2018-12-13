/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fprintf.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/13 15:58:23 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 16:35:16 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

static const t_conv	g_conv[] = {
	{ "diouxX", pf_int_arg },
	{ "b", pf_b_arg },
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
	while ((*str)[j] != '\0' && ft_charinstr((*str)[j], (char *)CONV_STR) == 0)
		j++;
	if ((*str)[j] == '\0')
		return (ft_strdup(""));
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
	while (i < (size_t)CONV_NB)
	{
		if (ft_charinstr(sub[ft_strlen(sub) - 1], g_conv[i].str) == 1)
			return (g_conv[i].func);
		i++;
	}
	return (NULL);
}

static void			ft_dispatch(char **str, size_t *i, va_list *ap)
{
	char			*sub;
	char			*res;
	t_pf_func		f;
	t_attributes	att;

	if ((sub = ft_extract(str, *i)) == NULL)
		return ;
	if (ft_strlen(sub) != 0)
	{
		if ((f = ft_select_func(sub)) == NULL)
			return ;
		ft_init_attributes(&att);
		ft_eval_attributes(&att, sub);
		res = NULL;
		res = (*f)(sub, ap, &att);
	}
	else
		res = ft_strdup(sub);
	if (res != NULL)
	{
		ft_replace(str, *i, res);
		*i += ft_strlen(res) - 1;
	}
	free(res);
	free(sub);
}

int					ft_fprintf(int fd, const char *format, ...)
{
	char	*str;
	va_list	ap;
	size_t	len_ret;
	size_t	i;

	if (format == NULL || fd == -1)
		return (0);
	if (ft_color_manager(format) == 1)
		return (1);
	if ((str = ft_strdup(format)) == NULL)
		return (-1);
	va_start(ap, format);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			ft_dispatch(&str, &i, &ap);
		i++;
	}
	i = ft_putstr_pf(str, fd);
	va_end(ap);
	len_ret = (int)ft_strlen(str) - (i * ft_strlen(N)) + i;
	free(str);
	return (len_ret);
}

/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_pc_arg.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 10:57:46 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/26 18:59:13 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../../includes/libft.h"

char	*pf_pc_arg(char *sub, va_list *ap, t_attributes *att)
{
	char	*res;

	if (sub != NULL && ap != NULL && att != NULL)
		;
	res = ft_strdup("%");
	return (res);
}

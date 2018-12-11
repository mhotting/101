/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/11 21:10:06 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 21:33:47 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./../../includes/libft.h"

static const char *g_col[11][2] =
{
	{ "{none}", C_NONE },
	{ "{blue}", C_BLUE },
	{ "{bold}", C_BOLD },
	{ "{black}", C_BLACK },
	{ "{red}", C_RED },
	{ "{green}", C_GREEN },
	{ "{brown}", C_BROWN },
	{ "{magenta}", C_MAGENTA },
	{ "{cyan}", C_CYAN },
	{ "{gray}", C_GRAY },
	{ "{yellow}", C_YELLOW }
};

void	ft_color_manager(char **format)
{
	if (format)
		;
	return ;
}

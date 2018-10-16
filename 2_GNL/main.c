/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mhotting <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 17:46:28 by mhotting     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/11 17:49:00 by mhotting    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*str;

	str = NULL;
	fd = open("file.txt", O_RDONLY);
	while (get_next_line(fd, &str) == 1)
	{
		printf("MAIN: %s\n", str);
		free(str);
	}
	close(fd);
}

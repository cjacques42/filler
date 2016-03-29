/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 09:14:32 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/29 14:43:10 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"
#include <fcntl.h>

int				main(void)
{
	char		*line;
	int			fd;

	fd = open("ret", O_CREAT | O_WRONLY | O_APPEND);
	while (get_next_line(0, &line) > 0)
	{
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
	}
	return (0);
}

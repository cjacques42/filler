/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 09:14:32 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/30 11:50:53 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int				main(void)
{
	char		*line;
	t_map		map;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strncmp(line, "$$$ exec p1", 11) == 0)
		{
			map.m_sign = 'o';
			map.o_sign = 'x';
			(ft_map(&map) != 0) ? ft_error() : 0;
		}
		else if (ft_strncmp(line, "$$$ exec p2", 11) == 0)
		{
			map.m_sign = 'x';
			map.o_sign = 'o';
			(ft_map(&map) != 0) ? ft_error() : 0;
		}
		else
			ft_error();
		free(line);
		free(map.board);
		free(map.pcs);
	}
	return (0);
}

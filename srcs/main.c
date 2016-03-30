/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 09:14:32 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/30 11:11:38 by cjacques         ###   ########.fr       */
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
		if (ft_strcmp(line, "$$$ exec p1 : [filler]") == 0)
		{
			map.sign = 'o';
			if (ft_map(&map) != 0)
				ft_error();
		}
		else if (ft_strcmp(line, "$$$ exec p2 : [filler]") == 0)
		{
			map.sign = 'x';
			if (ft_map(&map) != 0)
				ft_error();
		}
		else
			ft_error();
		free(map.board);
		free(map.pcs);
	}
	return (0);
}

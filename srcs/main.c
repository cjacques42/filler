/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 09:14:32 by cjacques          #+#    #+#             */
/*   Updated: 2016/04/01 18:31:01 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static void		ft_free_struct(t_map *map)
{
	free(map->board);
	free(map->pcs);
}

static void		ft_init_struct(t_map *map, char op, char my)
{
	map->board = NULL;
	map->pcs = NULL;
	map->m_sign = my;
	map->o_sign = op;
}

int				main(void)
{
	char		*line;
	t_map		map;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (ft_strncmp(line, "$$$ exec p1", 11) == 0)
		{
			ft_init_struct(&map, 'x', 'o');
			if (ft_map(&map) != 0)
				return (ft_error());
		}
		else if (ft_strncmp(line, "$$$ exec p2", 11) == 0)
		{
			ft_init_struct(&map, 'o', 'x');
			if (ft_map(&map) != 0)
				return (ft_error());
		}
		else
			ft_error();
		free(line);
		ft_free_struct(&map);
	}
	return (0);
}

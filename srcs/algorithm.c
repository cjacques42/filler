/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 12:19:38 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/30 18:03:47 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static int		ft_place(t_map *map, t_coord *ret)
{
	ret->x_b = ret->b_index / map->b_weidth;
	ret->y_b = ret->b_index % map->b_weidth;
	ret->x_p = ret->p_index / map->p_weidth;
	ret->y_p = ret->p_index % map->p_weidth;
	return (0);
}

static int		ft_putpcs(t_map *map, t_coord *ret)
{
	ret->p_index = 0;
	while (map->pcs[ret->p_index])
	{
		if (map->pcs[ret->p_index] == '*')
			if (ft_place(map, ret) == 0)
				return (0);
		ret->p_index++;
	}
	return (1);
}

int				ft_algorithm(t_map *map)
{
	t_coord		ret;

	ret.b_index = 0;
	while (map->board[ret.b_index])
	{
		if (map->board[ret.b_index] == map->sign
				|| map->board[ret.b_index] == map->sign - 32)
		{
			if (ft_putpcs(map, &ret) == 0)
				ft_printf("%d %d\n", ret.x, ret.y);
		}
		ret.b_index++;
	}
	return (0);
}

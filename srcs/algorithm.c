/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 12:19:38 by cjacques          #+#    #+#             */
/*   Updated: 2016/04/01 11:44:10 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static int		ft_check(t_map *map, t_coord *ret, int *count)
{
	ret->y_p = ret->p_index / map->p_weidth;
	ret->x_p = ret->p_index % map->p_weidth;
	ret->len = (ret->y_b + ret->y_p) * map->b_weidth +
		ret->x_b + ret->x_p;
	if (ret->y_b + ret->y_p >= map->b_height ||
			ret->x_b + ret->x_p >= map->b_weidth)
		return (1);
	if (map->board[ret->len] != '.')
	{
		if (map->board[ret->len] == map->m_sign ||
				map->board[ret->len] == map->m_sign - 32)
		{
			if (++(*count) > 1)
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

static int		ft_putpcs(t_map *map, t_coord *ret)
{
	int		count;

	count = 0;
	ret->y_b = ret->b_index / map->b_weidth;
	ret->x_b = ret->b_index % map->b_weidth;
	ret->x = ret->x_b;
	ret->y = ret->y_b;
	ret->p_index = 0;
	while (map->pcs[ret->p_index])
	{
		if (map->pcs[ret->p_index] == '*')
		{
			if (ft_check(map, ret, &count) == 1)
				return (1);
		}
		ret->p_index++;
	}
	if (count == 0)
		return (1);
	return (0);
}

int				ft_algorithm(t_map *map)
{
	t_coord		ret;

	ret.b_index = 0;
	while (map->board[ret.b_index])
	{
		if (ft_putpcs(map, &ret) == 0)
		{
			ft_printf("%d %d\n", ret.y, ret.x);
			return (0);
		}
		ret.b_index++;
	}
	ft_printf("%d %d\n", 0, 0);
	return (0);
}

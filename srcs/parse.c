/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:15:49 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/30 12:07:51 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

static int		ft_pcs(t_map *map)
{
	char	*line;
	int		index;

	line = NULL;
	index = 0;
	if ((map->pcs = ft_strnew(0)) == NULL)
		return (-1);
	while (index < map->p_height && get_next_line(0, &line))
	{
		if ((int)ft_strlen(line) != map->p_weidth)
			return (1);
		map->pcs = ft_strjoin_and_free(map->pcs, line, 1, 1);
		index++;
	}
	return (0);
}

static int		ft_board(t_map *map)
{
	char		*line;
	char		*ptr;
	int			index;

	line = NULL;
	index = 0;
	if ((map->board = ft_strnew(0)) == NULL)
		return (-1);
	while (index <= map->b_height && get_next_line(0, &line))
	{
		if (index++ > 0)
		{
			ptr = ft_strchr(line, ' ');
			if (ptr == NULL)
				return (1);
			if ((int)ft_strlen(ptr + 1) != map->b_weidth)
				return (1);
			map->board = ft_strjoin_and_free(map->board, ptr + 1, 1, 0);
		}
		free(line);
	}
	return (0);
}

int				ft_map(t_map *map)
{
	char	*line;
	char	**split;

	line = NULL;
	while (get_next_line(0, &line))
	{
		split = ft_strsplit(line, ' ');
		if (ft_count_split(split) != 3)
			return (1);
		if (ft_strncmp("Plateau", line, 7) == 0)
		{
			map->b_height = ft_atoi(split[1]);
			map->b_weidth = ft_atoi(split[2]);
			if (map->b_height == 0 || map->b_weidth == 0 || ft_board(map) != 0)
				return (1);
		}
		else if (ft_strncmp("Piece", line, 5) == 0)
		{
			map->p_height = ft_atoi(split[1]);
			map->p_weidth = ft_atoi(split[2]);
			if (map->p_height == 0 || map->p_weidth == 0 || ft_pcs(map) != 0)
				return (1);
		}
		ft_free_split(split);
		free(line);
	}
	return (0);
}

char			*ft_strjoin_and_free(char *s1, char *s2, int free1, int free2)
{
	char	*str;

	str = NULL;
	str = ft_strjoin(s1, s2);
	if (free1 == 1)
		free(s1);
	if (free2 == 1)
		free(s2);
	return (str);
}

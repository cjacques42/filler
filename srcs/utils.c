/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 09:45:00 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/30 14:55:12 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

void		ft_free_split(char **split)
{
	int		index;

	index = 0;
	while (split[index])
	{
		free(split[index]);
		index++;
	}
	free(split[index]);
	free(split);
}

int			ft_count_split(char **split)
{
	int		index;

	index = 0;
	while (split[index])
		index++;
	return (index);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 09:45:00 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/30 15:09:32 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"

int			ft_verif(char *str, char *c)
{
	int		index;

	index = 0;
	while (str[index])
	{
		if (ft_strchr(c, str[index]) == NULL)
			return (1);
		index++;
	}
	return (0);
}

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

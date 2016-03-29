/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 09:14:32 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/29 17:48:50 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_filler.h"
#include <fcntl.h>

int				main(void)
{
	t_list		list;
	t_listelem	*tmp;
	char		*line;
	int			fd;
	int			i;

	ft_list_init(&list, free);
	fd = open("new", O_CREAT | O_APPEND | O_WRONLY);
	i = 0;
	while (get_next_line(0, &line) > 0)
	{

		ft_printf("8 23\n");
		ft_putnbr_fd(i, fd);
		ft_putstr_fd("\n", fd);
		i++;
//		ft_list_ins_next(&list, LIST_TAIL(&list), line);
	}
	tmp = LIST_HEAD(&list);
	while (tmp != NULL)
	{
		ft_printf("%s\n", LIST_DATA(tmp));
		tmp = LIST_NEXT(tmp);
	}
	return (0);
}

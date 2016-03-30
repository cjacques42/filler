/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 13:45:35 by cjacques          #+#    #+#             */
/*   Updated: 2016/03/30 18:04:21 by cjacques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "ft_printf.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_map
{
	char	*board;
	char	*pcs;
	int		b_height;
	int		b_weidth;
	int		p_height;
	int		p_weidth;
	char	m_sign;
	char	o_sign;
}				t_map;

typedef struct	s_coord
{
	int		b_index;
	int		p_index;
	int		x_b;
	int		y_b;
	int		x_p;
	int		y_p;
	int		x;
	int		y;
}				t_coord;

void			ft_error(void);
int				ft_map(t_map *map);
void			ft_free_split(char **split);
int				ft_count_split(char **split);
char			*ft_strjoin_and_free(char *s1, char *s2, int free1, int free2);
int				ft_algorithm(t_map *map);
int				ft_contain(char *str, char *c);

#endif

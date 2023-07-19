/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smitsobo <smitsobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:43:31 by smitsobo          #+#    #+#             */
/*   Updated: 2023/07/12 18:58:03 by smitsobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_lines(char **map)
{
	int	i;

	while (map[i] != NULL)
		i++;
	return (i);
}

void	ft_findp(t_long *l)
{
	int	stop;

	stop = 0;
	l->p_x = 0;
	while (l->map[l->p_x] != NULL && stop == 0)
	{
		l->p_y = 0;
		while (l->map[l->p_x][l->p_y] != '\0' && stop == 0)
		{
			if (l->map[l->p_x][l->p_y] == 'P')
				stop = 1;
			else
				l->p_y += 1;
		}
		if (stop == 0)
			l->p_x += 1;
	}
}
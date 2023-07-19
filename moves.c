/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smitsobo <smitsobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:13:31 by smitsobo          #+#    #+#             */
/*   Updated: 2023/07/12 18:09:43 by smitsobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_long *l)
{	
	if (l->map[l->p_x - 1][l->p_y] != '1')
	{
		if (l->close_door == 1)
			l->map[l->p_x][l->p_y] = 'E';
		else
			l->map[l->p_x][l->p_y] = '0';
		if(l->map[l->p_x - 1][l->p_y] == 'E')
			l->close_door = 1;
		else
			l->close_door = 0;
		l->p_x -= 1;
		l->map[l->p_x][l->p_y] = 'P';
	}
}

void	ft_down(t_long *l)
{
	if (l->map[l->p_x + 1][l->p_y] != '1')
	{
		if (l->close_door == 1)
			l->map[l->p_x][l->p_y] = 'E';
		else
			l->map[l->p_x][l->p_y] = '0';
		if(l->map[l->p_x + 1][l->p_y] == 'E')
			l->close_door = 1;
		else
			l->close_door = 0;
		l->p_x += 1;
		l->map[l->p_x][l->p_y] = 'P';
	}
}

void	ft_right(t_long *l)
{
	if (l->map[l->p_x][l->p_y + 1] != '1')
	{
		if (l->close_door == 1)
			l->map[l->p_x][l->p_y] = 'E';
		else
			l->map[l->p_x][l->p_y] = '0';
		if(l->map[l->p_x][l->p_y + 1] == 'E')
			l->close_door = 1;
		else
			l->close_door = 0;
		l->p_y += 1;
		l->map[l->p_x][l->p_y] = 'P';
	}
}

void	ft_left(t_long *l)
{
	if (l->map[l->p_x][l->p_y - 1] != '1')
	{
		if (l->close_door == 1)
			l->map[l->p_x][l->p_y] = 'E';
		else
			l->map[l->p_x][l->p_y] = '0';
		if(l->map[l->p_x][l->p_y - 1] == 'E')
			l->close_door = 1;
		else
			l->close_door = 0;
		l->p_y -= 1;
		l->map[l->p_x][l->p_y] = 'P';
	}
}

int	handle_input(int key, t_long *l)
{
	if (key == 65307)
		exit (0);
	if (key == 97)
		ft_left(l);
	if (key == 100)
		ft_right(l);
	if (key == 'w')
		ft_up(l);
	if (key == 's')
		ft_down(l);
	gen_map(l);
	return (0);
}

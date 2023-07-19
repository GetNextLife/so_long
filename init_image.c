/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smitsobo <smitsobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:45:31 by smitsobo          #+#    #+#             */
/*   Updated: 2023/07/12 19:00:11 by smitsobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_long *l)
{
	int x;
	int y;

	x = ft_strlen(l->map[0]) * 64;
	y = ft_count_lines(l->map) * 64;
	ft_findp(l);
	l->mlx = mlx_init();
	l->win = mlx_new_window(l->mlx, x , y, "IL GIUOCO");
	l->wall = mlx_xpm_file_to_image(l->mlx, "imgs/wall.xpm", &l->w, &l->h);
	l->floor = mlx_xpm_file_to_image(l->mlx, "imgs/floor.xpm", &l->w, &l->h);
	l->exit = mlx_xpm_file_to_image(l->mlx, "imgs/exit.xpm", &l->w, &l->h);
	l->pers = mlx_xpm_file_to_image(l->mlx, "imgs/player.xpm", &l->w, &l->h);
	l->coll = mlx_xpm_file_to_image(l->mlx, "imgs/collect.xpm", &l->w, &l->h);
}

int	gen_map(t_long	*l)
{
	int	x;
	int	y;
	int	pix_x;
	int	pix_y;

	y = 0;
	pix_x = 0;
	while (l->map[y])
	{
		x = 0;
		pix_y = 0;
		while (l->map[y][x] && l->map[y][x] != '\n')
		{
			if (l->map[y][x] == '1')
				mlx_put_image_to_window(l->mlx, l->win, l->wall, pix_y, pix_x);
			if (l->map[y][x] == '0')
				mlx_put_image_to_window(l->mlx, l->win, l->floor, pix_y, pix_x);
			if (l->map[y][x] == 'E')
				mlx_put_image_to_window(l->mlx, l->win, l->exit, pix_y, pix_x);
			if (l->map[y][x] == 'P')
				mlx_put_image_to_window(l->mlx, l->win, l->pers, pix_y, pix_x);
			if (l->map[y][x] == 'C')
				mlx_put_image_to_window(l->mlx, l->win, l->coll, pix_y, pix_x);
			x++;
			pix_y += 64;
		}
		pix_x += 64;
		y++;
	}
	return (0);
}

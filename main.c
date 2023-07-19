/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smitsobo <smitsobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:21:21 by smitsobo          #+#    #+#             */
/*   Updated: 2023/07/12 17:53:33 by smitsobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_long	l;

	l.close_door = 0;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	l.map = get_map(fd);
	if (ft_controlmap(l.map) == 0)
	{
		close(fd);
		return (ft_free_matrix(l.map));
	}
	init_image(&l);
	mlx_loop_hook(l.mlx, gen_map, &l);
	mlx_hook(l.win, 17, 0, ft_free_matrix, &l);
	mlx_key_hook(l.win, handle_input, &l);
	mlx_loop(l.mlx);
	return (0);
}

char	**get_map(int fd)
{
	char	**map;
	char	*map_list;
	char	*cha;
	int		c;

	c = 1;
	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	cha = ft_calloc(1, 1);
	map_list = ft_calloc(0, 1);
	cha[0] = 'n';
	while (c > 0)
	{
		c = read(fd, cha, 1);
		if (c < 0)
			break ;
		map_list = strjoina(map_list, cha);
	}
	cha = ft_free(cha);
	map = ft_split(map_list, '\n');
	map_list = ft_free(map_list);
	return (map);
}

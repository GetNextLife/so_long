/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smitsobo <smitsobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:22:22 by smitsobo          #+#    #+#             */
/*   Updated: 2023/07/12 18:58:19 by smitsobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"

typedef struct s_checks
{
	int		e;
	int		p;
	int		c;
	int		i;
	int		j;
	int		flag;
}		t_checks;

typedef struct s_long
{
	char	**map;
	void	*mlx;
	void	*win;
	int		h;
	int		w;
	int		p_x;
	int		p_y;
	int		close_door;
	void	*floor;
	void	*wall;
	void	*pers;
	void	*exit;
	void	*coll;
}		t_long;

char		*strjoina(char *str, char *cont);
char		*ft_free(char *str);
char		*ft_calloc(size_t nmemb, size_t size);
char		**ft_split(char const *s, char c);
int			ft_free_matrix(char **matrix);
int			ft_strlen(char *cha);
int			check_lines(char **map);
int			check_str1(char *cha);
int			check_bord(char **map);
t_checks	ft_init_checks(void);
int			check_checks(t_checks checks);
void		little_control(t_checks *checks, char flag);
int			control_epc(char **map);
char		**get_map(int fd);
int			check_wrong_letter(char **map);
int			ft_find_i_j(char **map, t_checks *index, char flag);
void		flood_fill(int i, int j, char **map);
int			ft_controlmap(char **map);
int			ft_find(char **map, char c);
char		**ft_copymatrix(char **map);
int			gen_map(t_long	*l);
void		init_image(t_long *l);
int			ft_count_lines(char **map);
int			handle_input(int key, t_long *l);
void		ft_findp(t_long *l);

#endif

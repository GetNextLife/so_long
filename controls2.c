/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smitsobo <smitsobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:22:10 by smitsobo          #+#    #+#             */
/*   Updated: 2023/07/16 19:23:08 by smitsobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//controlla che i checks su e p c siano okay.

int	check_checks(t_checks checks)
{
	if (checks.e != 1)
		return (0);
	else if (checks.p != 1)
		return (0);
	else if (checks.c < 1)
		return (0);
	return (1);
}

int	check_wrong_letter(char **map)
{
	t_checks	index;

	index = ft_init_checks();
	while (map[index.i] != NULL)
	{
		index.j = 0;
		while (map[index.i][index.j] != '\0')
		{
			if (map[index.i][index.j] != 'P' && map[index.i][index.j] != 'E'
					&& map[index.i][index.j] != 'C' 
						&& map[index.i][index.j] != '1'
							&& map[index.i][index.j] != '0')
				return (0);
			index.j += 1;
		}
		index.i += 1;
	}
	return (1);
}


//si utilizza una sola funzione per trovare i e j di interesse. inserendo 
//l'indirizzo di index possiamo modificare le variabili della struttura. 
//se non trova nulla, restituisce 0.

int	ft_find_i_j(char **map, t_checks *index, char flag)
{
	while (map[index->i] != NULL)
	{
		index->j = 1;
		while (map[index->i][index->j] != '\0')
		{
			if (map[index->i][index->j] == 'P' && flag == 'p')
				return (1);
			if ((map[index->i][index->j] == 'C'
				|| map[index->i][index->j] == 'E') && flag == 'a')
				return (1);
			index->j += 1;
		}
		index->i += 1;
	}
	return (0);
}

//i e j sono gli index di p quando richiamo la prima volta.
//metto map[i][j] come 1, tanto io devo semplicemente trovare un path
//non so se la ricorrenza lo fa funzionare

void	flood_fill(int i, int j, char **map)
{
	if (map[i][j] == '1' && map[i][j])
		return ;
	else
	{
		map[i][j] = '1';
		flood_fill(i + 1, j, map);
		flood_fill(i, j + 1, map);
		flood_fill(i - 1, j, map);
		flood_fill(i, j - 1, map);
	}
}

//questa funzione considera i checker, per il flood_fill fa un ciclo e 
//controlla tutte le volte se la flag e` uguale a 0.
//manca anche il wrongletter

int	ft_controlmap(char **map)
{
	t_checks	p;
	char		**copy;

	p = ft_init_checks();
	ft_find_i_j(map, &p, 'p');
	copy = ft_copymatrix(map);
	flood_fill(p.i, p.j, copy);
	if (check_lines(map) == 0)
		return (0);
	if (control_epc(map) == 0)
		return (0);
	if (ft_find(copy, 'E') == 1 || ft_find(copy, 'C') == 1)
		return (ft_free_matrix(copy));
	if (check_wrong_letter(map) == 0)
		return (0);

	p.i = ft_free_matrix(copy);
	return (1);
}

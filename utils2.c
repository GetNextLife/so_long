/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smitsobo <smitsobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:43:31 by smitsobo          #+#    #+#             */
/*   Updated: 2023/07/11 17:40:12 by smitsobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_checks	ft_init_checks(void)
{
	t_checks	checks;

	checks.c = 0;
	checks.e = 0;
	checks.p = 0;
	checks.i = 0;
	checks.j = 0;
	checks.flag = 0;
	return (checks);
}

char	**calloc_matrix(char **map)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
		i++;
	copy = malloc((i + 1) * sizeof(char *)); 
	while (i >= 0)
	{
		copy[j] = ft_calloc(ft_strlen(map[0]), 1);
		i--;
		j++;
	}
	return (copy);
}

char	**ft_copymatrix(char **map)
{
	char	**copy;
	int		i;
	int		j;

	i = 0;
	copy = calloc_matrix(map);
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			copy[i][j] = map[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

int	ft_find(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

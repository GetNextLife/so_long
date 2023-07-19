/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smitsobo <smitsobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:21:51 by smitsobo          #+#    #+#             */
/*   Updated: 2023/07/12 17:45:14 by smitsobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//funzione che fa il check delle linee uguali e se il n. 
//delle linee e` diverso dal n. delle colonne (da 1 se e` tutto ok).

int	check_lines(char **map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(map[0]);
	while (map[i] != NULL)
	{

		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
		j++;
	}
	if (i == len)
		return (0);
	write(1, "qui\n", 4);
	return (1);
}

//questa funzione controlla che la stringa abbia solo 1 (1 se tutto ok)

int	check_str1(char *cha)
{
	int	i;

	i = 0;
	while (cha[i] != '\0')
	{
		if (cha[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

//questa funzione controlla che la matrice sia circondata da 1 (1 se ok)

int	check_bord(char **map)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(map[0]) - 1;
	if (check_str1(map[0]) == 0)
		return (0);
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][len] != '1')
			return (0);
		i++;
	}
	if (check_str1(map[i - 1]) == 0)
		return (0);
	return (1);
}

//cambia i check ogni volta che incontra una lettera;

void	little_control(t_checks *checks, char flag)
{
	if (flag == 'e')
		checks->e += 1;
	if (flag == 'p')
		checks->p = +1;
	if (flag == 'c')
		checks->c += 1;
}

//controlla che ci siano un E, un P ed almeno un C.

int	control_epc(char **map)
{
	int			i;
	int			j;
	t_checks	checks;

	i = 0;
	checks = ft_init_checks();
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				little_control(&checks, 'e');
			if (map[i][j] == 'P')
				little_control(&checks, 'p');
			if (map[i][j] == 'C')
				little_control(&checks, 'c');
			j++;
		}
		i++;
	}
	if (check_checks(checks) == 0)
		return (0);
	return (1);
}

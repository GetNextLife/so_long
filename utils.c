/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smitsobo <smitsobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:43:31 by smitsobo          #+#    #+#             */
/*   Updated: 2023/07/12 17:44:47 by smitsobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

int	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix)
	{
		while (matrix[i] != NULL)
		{
			matrix[i] = ft_free(matrix[i]);
			i++;
		}
		free(matrix);
		matrix = NULL;
	}
	return (0);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*cal;
	size_t	i;

	i = 0;
	cal = malloc((nmemb * size) + 1);
	if (!cal)
		return (cal = ft_free(cal));
	while (i <= nmemb * size)
	{
		cal[i] = '\0';
		i++;
	}
	return (cal);
}

//non faccio il free di cont, vediamo dopo se dovesse servire lo faccio.

char	*strjoina(char *str, char *cont)
{
	int		k;
	int		j;
	char	*joy;

	k = 0;
	while (str[k] != '\0')
		k++;
	j = 0;
	while (cont[j] != '\0')
		j++;
	joy = ft_calloc(k + j, 1);
	if (!joy)
		return (joy = ft_free(joy));
	k = -1;
	j = -1;
	while (str[++k] != '\0')
		joy[k] = str[k];
	str = ft_free(str);
	while (cont[++j] != '\0')
		joy[k + j] = cont[j];
	return (joy);
}

int	ft_strlen(char *cha)
{
	int	i;

	if (!cha)
		return (0);
	i = 0;
	while (cha[i])
		i++;
	return (i);
}

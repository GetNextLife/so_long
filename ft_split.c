/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smitsobo <smitsobo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:29:11 by smitsobo          #+#    #+#             */
/*   Updated: 2023/06/30 02:22:42 by smitsobo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_substrc( char const *s, unsigned int start, size_t len, char c)
{
	char	*str;
	size_t	i;

	str = (char *) malloc(len * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		if (s[start + i] == c || s[start + i] == '\0')
		{
			str[i] = '\0';
			return (str);
		}
		else
			str[i] = s[start + i];
		i++;
	}
	return (0);
}

static size_t	ft_charcount(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 1;
	while (s[i] != '\0' && c != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_ctoc(char const *s, char c, size_t i)
{
	size_t	count;

	count = 1;
	while (s[i] != '\0' && s[i] != c && c != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (s[i] != c && i == 0)
		mat = (char **)malloc((ft_charcount(s, c) + 1) * sizeof(char *));
	else
		mat = (char **)malloc(ft_charcount(s, c) * sizeof(char *));
	if (!mat)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
			if (i == 0 || s[i -1] == c)
				mat[k++] = ft_substrc(s, i, ft_ctoc(s, c, i), c);
		i++;
	}
	mat[k] = NULL;
	return (mat);
}

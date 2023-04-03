/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:27:20 by snourry           #+#    #+#             */
/*   Updated: 2022/01/27 00:06:33 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * This file contains all function for do a split on ft_split.
**/

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (c == charset[i])
			return (1);
	return (0);
}

int	ft_is_word(char c, char before, char *charset)
{
	return (ft_is_charset(before, charset) && !ft_is_charset(c, charset));
}

int	ft_size_tab(char *str, char *charset)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if ((i == 0 && !ft_is_charset(str[i], charset))
			|| (ft_is_charset(str[i - 1], charset)
				&& !ft_is_charset(str[i], charset)))
			count++;
	}
	return (count);
}

int	*ft_size_word(char *str, char *charset, int size)
{
	int	*tab;
	int	i;
	int	index;

	tab = malloc(sizeof(int) * size);
	i = 0;
	index = -1;
	while (++index < size)
		tab[index] = 0;
	index = 0;
	while (str[i])
	{
		if (!ft_is_charset(str[i], charset))
			tab[index]++;
		else if (i > 0 && ft_is_charset(str[i], charset))
			index++;
		i++;
	}
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	int		index;
	int		i[2];
	int		*size;
	char	**tab;

	tab = malloc(sizeof(char *) * (ft_size_tab(str, charset) + 1));
	index = 0;
	i[0] = -1;
	i[1] = 0;
	size = ft_size_word(str, charset, ft_size_tab(str, charset));
	while (str[++i[0]])
	{
		if (!ft_is_charset(str[i[0]], charset))
		{
			if (i[0] == 0 || ft_is_word(str[i[0]], str[i[0] - 1], charset))
				tab[index] = malloc(sizeof(char) * size[index] + 1);
			tab[index][i[1]] = str[i[0]];
			tab[index][++i[1]] = '\0';
		}
		else if (i[0] > 0 && !ft_is_charset(str[i[0] - 1], charset) && ++index)
			i[1] = 0;
	}
	tab[ft_size_tab(str, charset)] = 0;
	free(size);
	return (tab);
}

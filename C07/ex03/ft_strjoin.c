/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 02:43:00 by snourry           #+#    #+#             */
/*   Updated: 2022/02/03 18:02:37 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_size(char **strs, int size, char *sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
		count += ft_strlen(strs[i++]);
	count += ft_strlen(sep) * (size - 1);
	return (count);
}

char	*ft_spe_strcat(char *dest, char **strs, char *sep, int size)
{
	int	i;
	int	i_dest;
	int	i_sep;
	int	c_strs;

	i = -1;
	i_dest = 0;
	while (++i < size)
	{
		i_sep = -1;
		c_strs = -1;
		while (strs[i][++c_strs])
			dest[i_dest++] = strs[i][c_strs];
		while (sep[++i_sep] && i < size - 1)
			dest[i_dest++] = sep[i_sep];
	}
	dest[i_dest] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	char	*null;

	null = malloc(sizeof(char) * 1);
	*null = 0;
	if (size == 0)
		return (null);
	dest = malloc(sizeof(char) * ft_size(strs, size, sep) + 1);
	if (dest)
	{
		ft_spe_strcat(dest, strs, sep, size);
		return (dest);
	}
	return (NULL);
}

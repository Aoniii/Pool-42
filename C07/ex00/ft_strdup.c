/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 00:05:06 by snourry           #+#    #+#             */
/*   Updated: 2022/01/26 15:47:21 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		i;

	cpy = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (cpy)
	{
		i = -1;
		while (src[++i])
			cpy[i] = src[i];
		cpy[i] = '\0';
		return (cpy);
	}
	return (0);
}

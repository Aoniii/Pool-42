/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 02:35:18 by snourry           #+#    #+#             */
/*   Updated: 2022/01/30 02:35:20 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	ft_find(char *to_find, int i, char *str)
{
	int	a;

	a = 0;
	while (to_find[a])
		if (to_find[a++] != str[i++])
			return (0);
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = -1;
	if (!*to_find)
		return (str);
	while (str[++i])
		if (ft_find(to_find, i, str))
			return (&str[i]);
	ft_putstr("Dict Error\n");
	return (0);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

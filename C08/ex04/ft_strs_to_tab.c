/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 22:11:31 by snourry           #+#    #+#             */
/*   Updated: 2022/01/26 15:54:15 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
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

t_stock_str	ft_creat(char *str)
{
	t_stock_str	creat;

	creat.size = ft_strlen(str);
	creat.str = str;
	creat.copy = ft_strdup(str);
	return (creat);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < ac)
		tab[i] = ft_creat(av[i]);
	tab[i].str = 0;
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:03:28 by snourry           #+#    #+#             */
/*   Updated: 2022/01/27 18:27:50 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f) (int))
{
	int	*cpy;
	int	i;

	i = -1;
	cpy = malloc(sizeof(int) * length);
	if (!cpy)
		return (NULL);
	while (++i < length)
		cpy[i] = f(tab[i]);
	return (cpy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:28:54 by snourry           #+#    #+#             */
/*   Updated: 2022/02/01 19:28:55 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/**
 * This function write the board of map.
**/

void	ft_print_map(t_map *map)
{
	int		i;

	i = 0;
	while (++i < map->height + 1)
	{
		ft_putstr(map->board[i]);
		ft_putstr("\n");
	}
}

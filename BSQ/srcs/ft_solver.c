/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:11:30 by snourry           #+#    #+#             */
/*   Updated: 2022/02/01 21:37:07 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/**
 * This function return the minimal value of arguments.
**/

int	ft_get_minimun(int i1, int i2, int i3)
{
	int	tmp;

	tmp = i1;
	if (tmp > i2)
		tmp = i2;
	if (tmp > i3)
		tmp = i3;
	return (tmp);
}

/**
 * This function return value to solve.
**/

int	ft_get_value(int i1, int i2, int i3)
{
	if (i1 == i2 && i2 == i3)
		return (i1 + 1);
	return (ft_get_minimun(i1, i2, i3) + 1);
}

/**
 * This function solve the map.
**/

void	ft_solve(t_map *map)
{
	int	x;
	int	y;

	y = map->height - 1;
	while (--y > 0)
	{
		x = map->width - 1;
		while (--x >= 0)
		{
			if (map->map[y][x] != -1)
			{
				map->map[y][x] = ft_get_value(map->map[y + 1][x],
						map->map[y][x + 1], map->map[y + 1][x + 1]);
			}
		}
	}
}

/**
 * This function get the location of solve.
**/

t_location	get_solve_location(t_map *map)
{
	int			x;
	int			y;
	t_location	location;

	location.value = 0;
	y = map->height - 1;
	while (--y > 0)
	{
		x = map->width - 1;
		while (--x >= 0)
		{
			if (map->map[y][x] >= location.value)
			{
				location.value = map->map[y][x];
				location.x = x;
				location.y = y;
			}
		}
	}
	return (location);
}

/**
 * This function write the solve of map.
**/

void	ft_solve_writer(t_map *map)
{
	int			x;
	int			y;
	t_location	location;

	ft_solve(map);
	location = get_solve_location(map);
	y = location.y - 1;
	while (++y <= location.y + location.value)
	{
		x = location.x - 1;
		while (++x <= location.x + location.value)
		{
			map->board[y][x] = map->full;
		}
	}
}

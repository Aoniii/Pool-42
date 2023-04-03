/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:11:51 by snourry           #+#    #+#             */
/*   Updated: 2022/02/01 19:11:53 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/**
 * This function creat a map of file.
**/

t_map	*ft_map_creat(char *filename)
{
	t_map	*map;
	char	**board;

	map = malloc(sizeof(t_map));
	board = ft_file_get_board(filename);
	map->width = ft_strlen(board[1]);
	map->height = ft_atoi(board[0]);
	map->board = board;
	map->map = NULL;
	map->empty = board[0][ft_strlen(board[0]) - 3];
	map->full = board[0][ft_strlen(board[0]) - 1];
	map->obstacle = board[0][ft_strlen(board[0]) - 2];
	ft_init_map(map);
	return (map);
}

/**
 * This function creat a map of standard input.
**/

t_map	*ft_map_creat_input(char *str)
{
	t_map	*map;
	char	**board;

	map = malloc(sizeof(t_map));
	board = ft_input_get_board(str);
	map->width = ft_strlen(board[1]);
	map->height = ft_atoi(board[0]);
	map->board = board;
	map->map = NULL;
	map->empty = board[0][ft_strlen(board[0]) - 3];
	map->full = board[0][ft_strlen(board[0]) - 1];
	map->obstacle = board[0][ft_strlen(board[0]) - 2];
	ft_init_map(map);
	return (map);
}

/**
 * This function malloc the map.
**/

void	ft_malloc_map(t_map *map)
{
	int	i;

	i = -1;
	map->map = malloc(sizeof(int *) * map->height);
	if (!map->map)
		return ;
	while (++i < map->height)
	{
		map->map[i] = malloc(sizeof(int) * map->width);
		if (!map->map[i])
			return ;
	}
}

/**
 * This function init map of solver.
**/

void	ft_init_map(t_map *map)
{
	int	y;
	int	x;

	ft_malloc_map(map);
	y = 1;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->board[y][x] == map->obstacle)
				map->map[y][x] = -1;
			else if (y == map->height - 1 || x == map->width - 1)
				map->map[y][x] = 1;
			x++;
		}
		y++;
	}
}

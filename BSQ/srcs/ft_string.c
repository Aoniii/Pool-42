/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 00:09:10 by snourry           #+#    #+#             */
/*   Updated: 2022/02/01 00:09:12 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/**
 * This function return the length of string.
**/

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

/**
 * This function write a string.
**/

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

/**
 * This function convert ascii to integer.
**/

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	str[ft_strlen(str) - 3] = 'x';
	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result == 0)
			result = *str - 48;
		else
			result = (result * 10) + *str - 48;
		str++;
	}
	return (result * sign);
}

/**
 * This function free a board of string.
**/

void	ft_free_board(char **board)
{
	int	i;

	i = -1;
	while (board[++i])
	{
		free(board[i]);
		board[i] = NULL;
	}
	free(board);
	board = NULL;
}

/**
 * This function free a map.
**/

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->board[i])
	{
		free(map->board[i]);
		map->board[i] = NULL;
		i++;
	}
	free(map->board);
	map->board = NULL;
	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		map->map[i] = NULL;
		i++;
	}
	free(map->map);
	map->map = NULL;
	free(map);
	map = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:43:27 by snourry           #+#    #+#             */
/*   Updated: 2022/01/31 23:43:29 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/**
 * This function return and write the map error.
**/

int	ft_check_error(void)
{
	ft_putstr("map error\n");
	return (0);
}

/**
 * This function do all check of map.
**/

int	ft_check_global(char *filename)
{
	if (ft_file_is_exist(filename) <= 0)
		return (ft_check_error());
	if (!ft_check_size(filename))
		return (ft_check_error());
	if (!ft_check_char(filename))
		return (ft_check_error());
	return (1);
}

/**
 * This function check if all lines have same length,
 * and if width equal height.
**/

int	ft_check_size(char *filename)
{
	char	**board;
	int		line;
	int		size;
	int		r;

	board = ft_file_get_board(filename);
	line = 0;
	size = ft_strlen(board[1]);
	r = 1;
	while (board[++line] && board[line + 1])
		if (ft_strlen(board[line]) != size)
			r = 0;
	if (line != ft_atoi(board[0]))
		r = 0;
	ft_free_board(board);
	return (r);
}

/**
 * This function check if the characters is correct.
**/

int	ft_check_char(char *filename)
{
	char	**board;
	int		i[5];

	board = ft_file_get_board(filename);
	i[0] = board[0][ft_strlen(board[0]) - 2];
	i[1] = board[0][ft_strlen(board[0]) - 3];
	i[2] = 0;
	i[4] = 1;
	while (board[++i[2]])
	{
		i[3] = -1;
		while (board[i[2]][++i[3]])
			if (!(i[0] == board[i[2]][i[3]] || i[1] == board[i[2]][i[3]]))
				i[4] = 0;
	}
	ft_free_board(board);
	return (i[4]);
}

/**
 * This function check if standard input is correct.
**/

int	ft_check_input(char *str)
{
	char	**board;
	int		line;
	int		size;
	int		i[5];

	board = ft_input_get_board(str);
	line = 0;
	size = ft_strlen(board[1]);
	while (board[++line] && board[line + 1])
		if (ft_strlen(board[line]) != size)
			return (ft_check_error());
	if (line != ft_atoi(board[0]))
		return (ft_check_error());
	i[0] = board[0][ft_strlen(board[0]) - 2];
	i[1] = board[0][ft_strlen(board[0]) - 3];
	i[2] = 0;
	i[4] = 1;
	while (board[++i[2]])
	{
		i[3] = -1;
		while (board[i[2]][++i[3]])
			if (!(i[0] == board[i[2]][i[3]] || i[1] == board[i[2]][i[3]]))
				i[4] = 0;
	}
	ft_free_board(board);
	return (i[4]);
}
	
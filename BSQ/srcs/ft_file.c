/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:09:18 by snourry           #+#    #+#             */
/*   Updated: 2022/01/31 23:11:49 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/**
 * This fuction check if the file exist.
**/

int	ft_file_is_exist(char *filename)
{
	int		file;

	file = open(filename, 0);
	return (file);
}

/**
 * This fuction return the length of file.
**/

int	ft_file_get_length(char *filename)
{
	int		length;
	int		file;
	char	buff[2];

	length = 0;
	file = ft_file_is_exist(filename);
	while (read(file, buff, 1))
		length++;
	close(file);
	return (length);
}

/**
 * This fuction return the content of file to string.
**/

char	*ft_file_get_str(char *filename)
{
	char	*str;
	int		file;

	file = ft_file_is_exist(filename);
	str = malloc(sizeof(char) * (ft_file_get_length(filename) + 1));
	if (!str)
		return (0);
	read(file, str, ft_file_get_length(filename));
	close(file);
	return (str);
}

/**
 * This fuction return the content of file to board of string.
**/

char	**ft_file_get_board(char *filename)
{
	char	**board;
	char	*str;

	str = ft_file_get_str(filename);
	board = ft_split(str, "\n");
	free(str);
	return (board);
}

/**
 * This fuction creat a board with standard input.
**/

char	**ft_input_get_board(char *str)
{
	char	**board;

	board = ft_split(str, "\n");
	free(str);
	return (board);
}

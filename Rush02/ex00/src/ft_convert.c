/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bruno Da Silva <brda-sil@1E4.42angoulem    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:51:30 by snourry           #+#    #+#             */
/*   Updated: 2022/01/29 19:37:28 by Bruno Da Si      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
	ft_is_exist : verifie que ce dico exist
*/

int	ft_is_exist(char *name)
{
	int		file;

	file = open(name, 0);
	return (file);
}

/*
	ft_get_file_size : permet de recuperer la taille du fichier
*/

int	ft_get_file_size(char *name)
{
	int		size;
	int		file;
	char	buff[2];

	file = open(name, 0);
	if (ft_is_exist(name) <= 0)
		return (0);
	if (file <= 0)
	{
		close(file);
		return (0);
	}
	while (read(file, buff, 1))
		size++;
	close(file);
	return (size);
}

/*
	ft_get_file : permet d'obtenir le dico
*/

char	*ft_get_file(char *name)
{
	char	*str;
	int		file;

	file = open(name, 0);
	if (ft_is_exist(name) <= 0)
		return (0);
	if (file <= 0)
	{
		close(file);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_get_file_size(name) + 10));
	if (!str)
		return (0);
	read(file, str, ft_get_file_size(name));
	close(file);
	return (str);
}

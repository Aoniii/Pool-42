/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:50:09 by snourry           #+#    #+#             */
/*   Updated: 2022/01/23 16:11:04 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_nbr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return (0);
		if (str[i] >= '0' && str[i] <= '9')
			if (str[i + 1] >= '0' && str[i] <= '9')
				return (0);
	}
	return (1);
}

int	test_max(char *str, int max)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != ' ')
			if (str[i] - 48 > max)
				return (0);
	return (max);
}

int	get_size_str(char *str)
{
	int	count;
	int	i;
	int	result;

	if (!is_nbr(str))
		return (0);
	count = 1;
	i = -1;
	while (str[++i])
		if (str[i] == ' ' && str[i - 1] != ' ')
			count++;
	result = count / 4;
	result = test_max(str, result);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:14:26 by snourry           #+#    #+#             */
/*   Updated: 2022/01/23 23:30:18 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	set_indices_str(char *str)
{
	int	**indices;
	int	i;
	int	j;
	int	k;

	indices = get_indices();
	i = -1;
	j = 0;
	k = 0;
	while (str[++i])
	{
		if (str[i] != ' ')
		{
			indices[j][k++] = str[i] - 48;
			if (k == get_size())
			{
				j++;
				k = 0;
			}
		}
	}
}

void	init(int **tab)
{
	int	i;
	int	j;

	i = -1;
	while (++i < get_size())
	{
		j = -1;
		while (++j < get_size())
			tab[i][j] = 0;
	}
}

int	is_value(void)
{
	int	value;
	int	temp;
	int	i;
	int	j;

	value = 0;
	temp = get_size() + 1;
	while (--temp > 0)
		value += temp;
	i = -1;
	while (++i < get_size())
	{
		temp = 0;
		j = -1;
		while (++j < get_size())
		{
			temp += get_value(i, j);
		}
		if (temp != value)
			return (0);
	}
	return (1);
}

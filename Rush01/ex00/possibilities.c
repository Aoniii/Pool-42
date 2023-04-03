/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:20:21 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/01/23 21:22:09 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	***g_possible_values;

void	add_value(int x, int y, int valeur)
{
	if (g_possible_values[y][x][valeur] == 0)
		g_possible_values[y][x][valeur] = 1;
}

void	remove_value(int x, int y, int valeur)
{
	if (g_possible_values[x][y][valeur] == 1)
		g_possible_values[x][y][valeur] = 0;
}

void	init_possibilities(void)
{
	int	count;
	int	x;
	int	y;

	y = 0;
	g_possible_values = malloc(sizeof(void *) * get_size());
	while (y < get_size())
	{
		x = 0;
		g_possible_values[y] = malloc(sizeof(void *) * get_size());
		while (x < get_size())
		{
			count = 0;
			g_possible_values[y][x] = malloc(sizeof(void *) * get_size());
			while (count < get_size())
			{
				add_value(x, y, count);
				count++;
			}
			x++;
		}
		y++;
	}
}

int	***get_possible_values(void)
{
	return (g_possible_values);
}

int	*get_possibilities_for_xy(int x, int y)
{
	return (g_possible_values[x][y]);
}

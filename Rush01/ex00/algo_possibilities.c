/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_possibilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:58:45 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/01/23 21:26:57 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	check_all_possibilities(void)
{
	int	x;
	int	y;

	y = 0;
	while (y < get_size())
	{
		x = 0;
		while (x < get_size())
		{
			check_col_row(x, y);
			x++;
		}
		y++;
	}
}

void	check_col_row(int x, int y)
{
	int	i;

	if (get_value(x, y) != 0)
	{
		i = 0;
		while (i < get_size())
		{
			if (!get_value(i, y))
			{
				remove_value(i, y, get_value(x, y) - 1);
			}
			i++;
		}
		i = 0;
		while (i < get_size())
		{
			if (!get_value(x, i))
				remove_value(x, i, get_value(x, y) - 1);
			i++;
		}
	}
}

void	check_for_only_one(void)
{
	int	x;
	int	y;

	y = -1;
	while (++y < get_size())
	{
		x = -1;
		while (++x < get_size())
		{
			check_value_for_only_one(x, y);
		}
	}
}

void	check_value_for_only_one(int x, int y)
{
	int	valeur;
	int	only_one;
	int	***possible_values;

	possible_values = get_possible_values();
	valeur = -1;
	only_one = 0;
	while (++valeur < get_size())
	{
		if (possible_values[x][y][valeur] == 1)
		{
			if (only_one == 0)
			{
				only_one = valeur + 1;
			}
			else
				only_one = -1;
		}
	}
	if (only_one > 0)
		set_value(x, y, only_one);
}

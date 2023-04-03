/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 21:29:06 by snourry           #+#    #+#             */
/*   Updated: 2022/01/23 23:17:15 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

/** **************************************************************************
 ** For a given indice (TOP, BOT, etc and column/row index), fetch the      **
 ** coordinates of the case positioned at 'pos'(0 to 3), starting from      **
 ** the indice given, into x and y                                          **
 ** *************************************************************************/

void	get_coordinates(int pos, int indices_count, int col_row_count, int *xy)
{
	if (indices_count == 0)
	{
		xy[0] = col_row_count;
		xy[1] = pos;
	}
	else if (indices_count == 1)
	{
		xy[0] = col_row_count;
		xy[1] = get_size() - 1 - pos;
	}
	else if (indices_count == 2)
	{
		xy[0] = pos;
		xy[1] = col_row_count;
	}
	else if (indices_count == 3)
	{
		xy[0] = get_size() - 1 - pos;
		xy[1] = col_row_count;
	}
}

void	check_for_min(int i_count, int l_count)
{
	int	count;
	int	max_value;
	int	still_checking;
	int	xy[2];

	max_value = get_size();
	count = 1;
	still_checking = 1;
	while (count < get_size() && still_checking)
	{
		get_coordinates(get_size() - count, i_count, l_count, xy);
		if (get_value(xy[0], xy[1]) == max_value)
		{
			max_value--;
		}
		else if (get_value(xy[0], xy[1]) != 1)
			still_checking = 0;
		count++;
	}	
	if (get_single_indice(i_count, l_count) == 1 + get_size() - max_value)
	{
		get_coordinates(0, i_count, l_count, xy);
		set_value(xy[0], xy[1], max_value);
	}
}

void	check_for_max(int indices_count, int col_row_count)
{
	int	i;
	int	xy[2];

	if (get_single_indice(indices_count, col_row_count) == get_size())
	{
		i = 0;
		while (i < get_size())
		{
			get_coordinates(i, indices_count, col_row_count, xy);
			set_value(xy[0], xy[1], i + 1);
			i++;
		}
	}
}

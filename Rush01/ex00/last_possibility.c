/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_possibility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngrenoux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:11:38 by ngrenoux          #+#    #+#             */
/*   Updated: 2022/01/23 23:27:03 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	last_possibility(void)
{
	int	***possible_values;
	int	*values;
	int	i[3];

	values = malloc(sizeof(int) * get_size());
	i[0] = -1;
	while (++i[0] < get_size())
		values[i[0]] = 0;
	possible_values = get_possible_values();
	i[2] = -1;
	while (++i[2] < get_size())
	{
		i[1] = -1;
		while (++i[1] < get_size())
		{
			i[0] = -1;
			while (++i[0] < get_size())
				if (possible_values[i[2]][i[1]][i[0]] > 0)
					values[i[0]]++;
		}
		check_last_poss(i[2], values, possible_values);
		i[0] = -1;
		while (++i[0] < get_size())
			values[i[0]] = 0;
	}
}

void	check_last_poss(int y, int *values, int ***poss_val)
{
	int	x;
	int	value_to_set;
	int	count;

	count = -1;
	value_to_set = -1;
	while (++count < get_size())
		if (values[count] == 1)
			value_to_set = count;
	if (value_to_set > -1)
	{
		x = -1;
		while (++x < get_size())
		{
			count = -1;
			while (++count < get_size())
				if (count == value_to_set && poss_val[y][x][count] == 1)
					set_value(y, x, value_to_set + 1);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 16:05:38 by snourry           #+#    #+#             */
/*   Updated: 2022/01/23 22:38:01 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_solvable(void)
{
	int	i;
	int	calc;

	i = 0;
	while (i < get_size())
	{
		calc = get_single_indice(0, i) + get_single_indice(1, i);
		if (calc < 3 || calc > get_size() + 1)
			return (0);
		i++;
	}
	i = 0;
	while (i < get_size())
	{
		calc = get_single_indice(2, i) + get_single_indice(3, i);
		if (calc < 3 || calc > get_size() + 1)
			return (0);
		i++;
	}
	return (1);
}

int	**solver(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < get_size())
	{
		j = -1;
		while (++j < get_size())
		{
			set_has_changed(0);
			check_for_min(i, j);
			check_for_max(i, j);
			check_for_only_one();
		}
		if (get_has_changed())
		{
			i = -1;
		}
	}
	return (get_matrice());
}

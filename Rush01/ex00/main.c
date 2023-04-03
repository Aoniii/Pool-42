/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:13:03 by snourry           #+#    #+#             */
/*   Updated: 2022/01/23 20:40:45 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	all_init(void)
{
	int	**indices;
	int	**matrice;
	int	i;

	indices = malloc(sizeof(void *) * 4);
	matrice = malloc(sizeof(void *) * get_size());
	set_matrice(matrice);
	set_indices(indices);
	i = -1;
	while (i++ < get_size())
	{
		matrice[i] = malloc(sizeof(int) * get_size());
		indices[i] = malloc(sizeof(int) * get_size());
	}
	init(get_matrice());
	init_possibilities();
}

int	main(int argc, char *argv[])
{
	if (argc != 2 || get_size_str(argv[1]) < 4)
		return (error());
	set_size(get_size_str(argv[1]));
	all_init();
	set_indices_str(argv[1]);
	if (!is_solvable())
		return (error());
	solver();
	if (!is_value())
		return (error());
	print();
	return (0);
}

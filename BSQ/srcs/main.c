/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:27:00 by snourry           #+#    #+#             */
/*   Updated: 2022/01/31 22:27:02 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>

void	ft_execute(int type, char *str)
{
	t_map	*map;

	if (type == 0)
	{
		map = ft_map_creat_input(str);
		ft_solve_writer(map);
		ft_print_map(map);
		ft_free_map(map);
	}
	else
	{
		map = ft_map_creat(str);
		ft_solve_writer(map);
		ft_print_map(map);
		ft_free_map(map);
	}
}

int	main(int ac, char **av)
{
	char	*str;
	int		i;

	str = NULL;
	if (ac < 2)
	{
		read(0, str, read(0, str, 8192));
		if (ft_check_input(str))
			ft_execute(0, str);
	}
	i = 0;
	while (++i < ac)
	{
		if (ft_check_global(av[i]))
			ft_execute(1, str);
		if (i < ac - 1)
			ft_putstr("\n");
	}
	return (0);
}

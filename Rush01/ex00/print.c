/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 23:02:39 by snourry           #+#    #+#             */
/*   Updated: 2022/01/23 17:58:30 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

void	print(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < get_size())
	{
		j = -1;
		while (++j < get_size())
		{
			if (j != get_size() && j != 0)
				ft_putchar(' ');
			ft_putchar(get_value(j, i) + 48);
		}
		ft_putchar('\n');
	}
}

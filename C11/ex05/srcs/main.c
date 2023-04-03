/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:26:12 by snourry           #+#    #+#             */
/*   Updated: 2022/01/30 02:21:50 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	ft_calculate(int i1, int i2, int (*f) (int, int))
{
	f(i1, i2);
	ft_putchar('\n');
	return (0);
}

int	ft_get_sign(int i1, int i2, char c)
{
	if (c == '+')
		return (ft_calculate(i1, i2, ft_addition));
	if (c == '-')
		return (ft_calculate(i1, i2, ft_subtraction));
	if (c == '*')
		return (ft_calculate(i1, i2, ft_multiplication));
	if (c == '/')
		return (ft_calculate(i1, i2, ft_division));
	if (c == '%')
		return (ft_calculate(i1, i2, ft_modulo));
	return (0);
}

int	ft_error(void)
{
	write(1, "0\n", 2);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	if (!ft_is_symbol(av[2]))
		return (ft_error());
	return (ft_get_sign(ft_atoi(av[1]), ft_atoi(av[3]), av[2][0]));
}

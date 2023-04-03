/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 01:10:00 by snourry           #+#    #+#             */
/*   Updated: 2022/01/30 01:10:01 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	ft_addition(int i1, int i2)
{
	ft_putnbr(i1 + i2);
	return (0);
}

int	ft_subtraction(int i1, int i2)
{
	ft_putnbr(i1 - i2);
	return (0);
}

int	ft_multiplication(int i1, int i2)
{
	ft_putnbr(i1 * i2);
	return (0);
}

int	ft_division(int i1, int i2)
{
	if (i2 == 0)
	{
		write(1, "Stop : division by zero", 23);
		return (0);
	}
	ft_putnbr(i1 / i2);
	return (0);
}

int	ft_modulo(int i1, int i2)
{
	if (i2 == 0)
	{
		write(1, "Stop : modulo by zero", 21);
		return (0);
	}
	ft_putnbr(i1 % i2);
	return (0);
}

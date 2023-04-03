/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 00:29:16 by snourry           #+#    #+#             */
/*   Updated: 2022/01/24 16:19:42 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_check(char *base)
{
	int	i;
	int	j;

	if (!base || ft_strlen(base) <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i] && i != j)
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	nb;

	if (!ft_check(base))
		return ;
	nb = (long int) nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb / ft_strlen(base) > 0)
		ft_putnbr_base(nb / ft_strlen(base), base);
	write(1, &base[nb % ft_strlen(base)], 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:04:13 by snourry           #+#    #+#             */
/*   Updated: 2022/02/03 18:05:50 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_is_in_base(char c, char *base);
int		ft_in_base(char c, char *base);
void	ft_add_dest(char *base, char *dest, int nbr, int index);

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) <= 1 || !base)
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
		if ((base[i] >= '\t' && base[i] <= '\r') || base[i] == ' '
			|| (base[i] == '+' || base[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *nbr, char *base)
{
	int	i;
	int	result;
	int	signes;

	i = 0;
	signes = 1;
	result = 0;
	while ((nbr[i] >= '\t' && nbr[i] <= '\r') || nbr[i] == ' ')
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			signes *= -1;
		i++;
	}
	while (nbr[i] && ft_is_in_base(nbr[i], base))
	{
		result = result * ft_strlen(base) + ft_in_base(nbr[i], base);
		i++;
	}
	return (result * signes);
}

int	ft_malloc_dest(long nbr, char *base)
{
	int	size;

	size = 0;
	if (nbr < 0)
	{
		size++;
		nbr *= -1;
	}
	while (nbr >= ft_strlen(base))
	{
		size++;
		nbr /= ft_strlen(base);
	}
	return (size);
}

char	*ft_putnbr_base(long nbr, char *base, char *dest)
{
	int	count;

	count = ft_malloc_dest((long)nbr, base);
	dest = malloc(sizeof(char) * count + 1);
	if (nbr < 0)
	{
		dest[0] = '-';
		nbr *= -1;
	}
	ft_add_dest(base, dest, nbr, count);
	dest[count + 1] = '\0';
	return (dest);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i_nbr;
	char	*dest;

	dest = NULL;
	if (!ft_check_base(base_to) || !ft_check_base(base_from))
		return (NULL);
	i_nbr = ft_atoi_base(nbr, base_from);
	dest = ft_putnbr_base(i_nbr, base_to, dest);
	return (dest);
}

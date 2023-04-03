/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bruno Da Silva <brda-sil@1E4.42angoulem    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:53:14 by Bruno Da Si       #+#    #+#             */
/*   Updated: 2022/01/29 16:49:21 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

long long	ft_atol(char *str)
{
	long long	integer;
	long long	is_negative;

	integer = 0;
	is_negative = 1;
	if (*str == '-')
	{
		is_negative *= -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		integer = integer * 10 + (*str - '0');
		str++;
	}
	return (integer * is_negative);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	dest[i] = ' ';
	i++;
	while (src[i] && j < nb)
	{
		if (src[j] == ' ' && src[j - 1] == ' ')
			j++;
		else
		{
			dest[i] = src[j];
			i++;
			j++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/*
	permet de creer la sortie
	(fonction la plus important)
	(elle nous sauves sur plein de truc)
*/

char	*ft_cut(char *str, char *output)
{
	int	i;
	int	i1;

	if (str[0] == 48 && output[0] != 0)
		return (output);
	i = 0;
	while (str[i] != ':')
		i++;
	i++;
	while (str[i] == ' ')
		i++;
	i1 = i;
	while (str[i1] != '\n')
		i1++;
	i1 -= i;
	ft_strncat(output, &str[i], i1);
	return (output);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:33:25 by snourry           #+#    #+#             */
/*   Updated: 2022/01/24 16:30:07 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	i = -1;
	while (base[++i])
	{
		j = i;
		while (base[++j])
			if (base[j] == base[i] && i != j)
				return (0);
		if (base[i] == '-' || base[i] == '+' || base[i] == ' ')
			return (0);
		if (base[i] >= '\t' && base[i] <= '\r')
			return (0);
	}
	return (1);
}

int	ft_calculate(int result, char c, char *base)
{
	int	i;

	i = 0;
	if (result == -1)
		result = 0;
	result *= ft_strlen(base);
	while (base[i])
	{
		if (base[i++] == c)
		{
			result += i - 1;
			return (result);
		}
	}
	return (result);
}

int	ft_is_contains(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
		if (base[i++] == c)
			return (1);
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	s;
	int	r;

	i = -1;
	s = 1;
	r = -1;
	if (!ft_check(base))
		return (0);
	while (str[++i])
	{
		if (ft_is_contains(str[i], base))
			r = ft_calculate(r, str[i], base);
		else if ((str[i] == ' ' || str[i] == '+' || str[i] == '-') && r < 0)
		{
			if (str[i] == '-')
				s *= -1;
		}
		else
			return (r * s);
	}
	return (r * s);
}

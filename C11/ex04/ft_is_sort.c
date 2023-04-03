/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:02:44 by snourry           #+#    #+#             */
/*   Updated: 2022/01/30 19:11:02 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ascending(int *tab, int length, int (*f) (int, int))
{
	int	i;

	i = -1;
	while (++i < length - 1)
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
	return (1);
}

int	ft_descending(int *tab, int length, int (*f) (int, int))
{
	int	i;

	i = -1;
	while (++i < length - 1)
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f) (int, int))
{
	if (ft_ascending(tab, length, f))
		return (1);
	else if (ft_descending(tab, length, f))
		return (1);
	return (0);
}

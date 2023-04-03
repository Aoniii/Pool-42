/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:47:20 by snourry           #+#    #+#             */
/*   Updated: 2022/01/12 22:59:23 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(char *c, int n)
{
	if (c[0] == '0' + 10 - n)
	{
		write(1, c, n);
	}
	else
	{
		write(1, c, n + 2);
	}
}

void	ft_print_combn(int n)
{
	char	c[12];
	int		i;

	c[0] = '0';
	c[n] = ',';
	c[n + 1] = ' ';
	i = 0;
	if (n < 1 || n > 9)
		return ;
	while (i++ < n - 1)
		c[i] = c[i - 1] + 1;
	while (c[0] <= '0' + 10 - n)
	{
		i = 1;
		ft_write(c, n);
		c[n - i]++;
		if (c[n - 1] == '0' + 10)
		{
			c[0]++;
			i = 0;
			while (i++ < n - 1)
				c[i] = c[i - 1] + 1;
		}	
	}
}

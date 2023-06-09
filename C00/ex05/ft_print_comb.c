/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:53:32 by snourry           #+#    #+#             */
/*   Updated: 2022/01/14 00:26:31 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(char *c)
{
	if (c[0] < c[1] && c[1] < c[2])
	{
		if (c[0] == '7')
		{
			write(1, c, 3);
		}
		else
		{
			write(1, c, 5);
		}
	}
}

void	ft_print_comb(void)
{
	char	c[5];

	c[0] = '0';
	c[3] = ',';
	c[4] = ' ';
	while (c[0] < '8')
	{
		c[1] = c[0] + 1;
		while (c[1] < '9')
		{
			c[2] = c[1] + 1;
			while (c[2] < '9' + 1)
			{
				ft_write(c);
				c[2]++;
			}
			c[1]++;
		}
		c[0]++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:31:53 by snourry           #+#    #+#             */
/*   Updated: 2022/01/16 22:41:41 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_printable(unsigned char c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

void	ft_to_hexa(unsigned char c)
{
	char			*base;
	unsigned char	h;

	h = c;
	base = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(base[h / 16]);
	ft_putchar(base[h % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	*src;

	i = 0;
	src = (unsigned char *)str;
	while (src[i])
	{
		if (!ft_is_printable(src[i]))
			ft_to_hexa(src[i++]);
		else
			ft_putchar(src[i++]);
	}
}

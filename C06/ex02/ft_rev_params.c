/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:54:23 by snourry           #+#    #+#             */
/*   Updated: 2022/01/20 15:56:02 by snourry          ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (++i < argc && argc != 0)
	{
		write(1, argv[argc - i], ft_strlen(argv[argc - i]));
		write(1, "\n", 1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:01:18 by snourry           #+#    #+#             */
/*   Updated: 2022/01/21 20:23:57 by snourry          ###   ########.fr       */
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

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i] || s2[i])
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*c;
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				c = argv[i];
				argv[i] = argv[i + 1];
				argv[i + 1] = c;
				i = 1;
			}
			else
				i++;
		}
	}
	i = 1;
	while (i < argc)
		ft_putstr(argv[i++]);
	return (0);
}

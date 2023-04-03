/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bruno Da Silva <brda-sil@1E4.42angoulem    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:36:08 by brda-sil          #+#    #+#             */
/*   Updated: 2022/01/15 17:46:17 by Bruno Da Si      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(const char character);

void	choose_colonne(char left_side, char center, char right_side, int x)
{
	int	colonne;

	colonne = 0;
	while (colonne < x)
	{
		if (colonne == 0)
			ft_putchar(left_side);
		else if (colonne < x - 1)
			ft_putchar(center);
		else
			ft_putchar(right_side);
		colonne++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	ligne;

	ligne = 0;
	while (ligne < y)
	{
		if (ligne == 0)
			choose_colonne('A', 'B', 'A', x);
		else if (ligne < y - 1)
			choose_colonne('B', ' ', 'B', x);
		else
			choose_colonne('C', 'B', 'C', x);
		ligne++;
	}
}

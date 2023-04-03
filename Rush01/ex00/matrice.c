/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:40:47 by johrober          #+#    #+#             */
/*   Updated: 2022/01/23 21:50:43 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	**g_matrice;

int	**get_matrice(void)
{
	return (g_matrice);
}

void	set_matrice(int **matrice)
{
	g_matrice = matrice;
}

int	get_value(int x, int y)
{
	return (g_matrice[x][y]);
}

void	set_value(int x, int y, int value)
{
	if (g_matrice[x][y] == 0)
	{
		g_matrice[x][y] = value;
		set_has_changed(1);
		check_col_row(x, y);
		last_possibility();
	}
	else if (g_matrice[x][y] > 0 && value == 0)
	{
		g_matrice[x][y] = value;
	}
}

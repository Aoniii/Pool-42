/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:37:35 by johrober          #+#    #+#             */
/*   Updated: 2022/01/23 16:54:21 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	**g_indices;

int	**get_indices(void)
{
	return (g_indices);
}

void	set_indices(int **indices)
{
	g_indices = indices;
}

int	get_single_indice(int indices_count, int col_row_count)
{
	return (g_indices[indices_count][col_row_count]);
}

/*int	set_single_indice(int indices_count, int col_row_count)
{
}*/

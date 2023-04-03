/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johrober <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:17:09 by johrober          #+#    #+#             */
/*   Updated: 2022/01/23 18:23:38 by johrober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	g_size;
static int	g_has_changed;

int	get_size(void)
{
	return (g_size);
}

void	set_size(int size)
{
	g_size = size;
}

void	set_has_changed(int has_changed)
{
	g_has_changed = has_changed;
}

int	get_has_changed(void)
{
	return (g_has_changed);
}

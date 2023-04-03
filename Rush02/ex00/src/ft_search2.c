/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:10:04 by snourry           #+#    #+#             */
/*   Updated: 2022/01/30 14:10:05 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
	gerer les billions
*/

void	ft_search_billion(char *nbr, char *dico, char *output)
{
	char	tmp[2];

	tmp[0] = nbr[0];
	tmp[1] = 0;
	ft_search_global(tmp, dico, output);
	ft_search_global("1000000000", dico, output);
	ft_search_base(&nbr[1], dico, output);
}

/*
	gerer les millions
*/

void	ft_search_million(char *nbr, char *dico, char *output)
{
	int		c;
	char	tmp[3];

	c = ft_strlen(nbr) - 6;
	tmp[0] = nbr[0];
	if (c == 3)
	{
		tmp[1] = nbr[1];
		tmp[2] = nbr[2];
		ft_put_three(tmp, dico, output);
	}
	else if (c == 2)
	{
		tmp[1] = nbr[1];
		tmp[2] = 0;
		ft_put_two(tmp, dico, output);
	}
	else
		ft_search_global(tmp, dico, output);
	tmp[0] = nbr[c];
	tmp[1] = nbr[c + 1];
	tmp[2] = nbr[c + 2];
	if (!(nbr[c - 3] == '0' && nbr[c - 2] == '0' && nbr[c - 1] == '0'))
		ft_search_global("1000000", dico, output);
	ft_search_base(&nbr[c], dico, output);
}

/*
	gerer les milliers
*/

void	ft_search_thousand(char *nbr, char *dico, char *output)
{
	int		c;
	char	tmp[3];

	c = ft_strlen(nbr) - 3;
	tmp[0] = nbr[0];
	if (c == 3)
	{
		tmp[1] = nbr[1];
		tmp[2] = nbr[2];
		ft_put_three(tmp, dico, output);
	}
	else if (c == 2)
	{
		tmp[1] = nbr[1];
		tmp[2] = 0;
		ft_put_two(tmp, dico, output);
	}
	else
		ft_search_global(tmp, dico, output);
	tmp[0] = nbr[c];
	tmp[1] = nbr[c + 1];
	tmp[2] = nbr[c + 2];
	if (!(nbr[c - 3] == '0' && nbr[c - 2] == '0' && nbr[c - 1] == '0'))
		ft_search_global("1000", dico, output);
	ft_search_base(tmp, dico, output);
}

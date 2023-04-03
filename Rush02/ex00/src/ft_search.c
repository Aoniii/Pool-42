/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bruno Da Silva <brda-sil@1E4.42angoulem    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:14:00 by Bruno Da Si       #+#    #+#             */
/*   Updated: 2022/01/29 19:39:46 by Bruno Da Si      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
	ft_search_dico : permet de lancer le parse
*/

void	ft_search_dico(char *nbr, char *dico, char *output)
{
	if (nbr[0] == '0' && ft_strlen(nbr) != 1)
	{
		ft_putstr("Error\n");
		return ;
	}
	ft_search_base(nbr, dico, output);
	ft_putstr(&output[1]);
	if (output[1])
		ft_putstr("\n");
}

/*
	ft_search_base : permet de savoir comment et dans quel ordre ecrire print la sortie
*/

void	ft_search_base(char *nbr, char *dico, char *output)
{
	int		character;

	character = ft_strlen(nbr);
	if (character == 10)
		ft_search_billion(nbr, dico, output);
	else if (character > 6 && character <= 9)
		ft_search_million(nbr, dico, output);
	else if (character > 3 && character <= 6)
		ft_search_thousand(nbr, dico, output);
	else if (character == 3)
		ft_put_three(nbr, dico, output);
	else if (character == 2)
		ft_put_two(nbr, dico, output);
	else
		ft_search_global(nbr, dico, output);
}

/*
	ft_search_global : permet d'ajouter a la sortie ce qu'il faudra print
*/

int	ft_search_global(char *nbr, char *dico, char *output)
{
	char	*str;

	str = ft_strstr(dico, nbr);
	if (str)
	{
		ft_cut(str, output);
		return (1);
	}
	else
		output[1] = 0;
	return (0);
}

/*
	ft_put_three : permet d'ecrire les groupes de 3
*/

void	ft_put_three(char *nbr, char *dico, char *output)
{
	char	tmp[2];

	tmp[0] = nbr[0];
	tmp[1] = 0;
	ft_search_global(tmp, dico, output);
	if (nbr[0] != '0')
		ft_search_global("100", dico, output);
	ft_put_two(&nbr[1], dico, output);
}

/*
	ft_put_two : permet d'ecrire les groupes de 2
*/

void	ft_put_two(char *nbr, char *dico, char *output)
{
	char	tmp[2];

	if (nbr[0] != '0' && nbr[0] == '1')
		ft_search_global(nbr, dico, output);
	else
	{
		tmp[0] = nbr[0];
		tmp[1] = '0';
		if (tmp[0] != '0')
			ft_search_global(tmp, dico, output);
		if (nbr[1] != '0')
			ft_search_global(&nbr[1], dico, output);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bruno Da Silva <brda-sil@1E4.42angoulem    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 11:19:14 by snourry           #+#    #+#             */
/*   Updated: 2022/01/30 14:18:45 by ngrenoux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

/*
	init : permet de malloc le dico et la sortie, et meme temps d'initialiser le dico.
*/

char	*init(int type, char *name)
{
	char	*dico;
	char	*output;

	if (type == 0)
	{
		dico = ft_get_file(name);
		return (dico);
	}
	if (type == 1)
	{
		(void) name;
		output = malloc(sizeof(char) * 512);
		if (!output)
			return (NULL);
		output[0] = 0;
		return (output);
	}
	return (NULL);
}

/*
		Main permet de :
	- lancer le programme !
	- verifier la presence du dico
	- d'afficher les erreurs
	- de lancer le parse et le print
	- free les variables apres utilisation
*/

int	main(int ac, char **av)
{
	char	*dico;
	char	*output;
	char	*name;
	int		i;

	i = 1;
	name = "./lib/numbers.dict";
	if (ac == 3)
		name = av[i++];
	if (ft_is_exist(name) <= 0)
	{
		ft_putstr("Dict Error\n");
		return (0);
	}
	dico = init(0, name);
	output = init(1, name);
	if ((ac == 2 || ac == 3) && (ft_str_is_numeric(av[i])
			&& ft_atol(av[i]) <= 4294967295))
		ft_search_dico(av[i], dico, output);
	else
		ft_putstr("Error\n");
	free(dico);
	free(output);
	return (0);
}

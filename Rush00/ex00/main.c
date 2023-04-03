/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bruno Da Silva <brda-sil@1E4.42angoulem    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:29:27 by brda-sil          #+#    #+#             */
/*   Updated: 2022/01/18 10:55:10 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	rush(int x, int y);

int	main(int argc, char *argv[])
{
	(void) argc;
	rush(atoi(argv[1]), atoi(argv[2]));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:17:56 by snourry           #+#    #+#             */
/*   Updated: 2022/01/19 15:22:07 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] && i < size)
		i++;
	if (i < size)
	{
		while (src[j] && i + 1 < size)
			dest[i++] = src[j++];
		dest[i] = '\0';
	}
	while (src[j++])
		i++;
	return (i);
}

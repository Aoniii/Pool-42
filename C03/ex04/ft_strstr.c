/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:16:52 by snourry           #+#    #+#             */
/*   Updated: 2022/01/20 15:19:01 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find(char *to_find, int i, char *str)
{
	int	a;

	a = 0;
	while (to_find[a])
		if (to_find[a++] != str[i++])
			return (0);
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = -1;
	if (!*to_find)
		return (str);
	while (str[++i])
		if (ft_find(to_find, i, str))
			return (&str[i]);
	return (0);
}

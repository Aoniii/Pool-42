/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 00:55:41 by snourry           #+#    #+#             */
/*   Updated: 2022/01/30 00:56:32 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>

/* ft_maths.c */
int		ft_addition(int i1, int i2);
int		ft_subtraction(int i1, int i2);
int		ft_multiplication(int i1, int i2);
int		ft_division(int i1, int i2);
int		ft_modulo(int i1, int i2);

/* ft_string.c */
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_is_symbol(char *str);

#endif

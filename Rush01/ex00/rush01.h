/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:29:37 by snourry           #+#    #+#             */
/*   Updated: 2022/01/23 23:29:09 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

/**algo_possibilities.c**/
void	check_all_possibilities(void);
void	check_col_row(int x, int y);
void	check_value_for_only_one(int x, int y);
void	check_for_only_one(void);

/**algo.c**/
void	get_coordinates(int pos, int indices_count, int col_row_count, int *xy);
void	check_for_min(int i_count, int l_count);
void	check_for_max(int indices_count, int col_row_count);

/**indices.c**/
int		**get_indices(void);
void	set_indices(int **indices);
int		get_single_indice(int indices_count, int col_row_count);

/**last_possibility.c**/
void	last_possibility(void);
void	check_last_poss(int y, int *values, int ***poss_val);

/**maths.c**/
int		is_nbr(char *str);
int		test_max(char *str, int max);
int		get_size_str(char *str);

/**matrice.c**/
int		**get_matrice(void);
void	set_matrice(int **matrice);
int		get_value(int x, int y);
void	set_value(int x, int y, int value);

/**matrice2.c**/
int		get_size(void);
void	set_size(int size);
int		get_has_changed(void);
void	set_has_changed(int has_changed);

/**possibilities.c**/
void	add_value(int x, int y, int valeur);
void	remove_value(int x, int y, int valeur);
void	init_possibilities(void);
int		***get_possible_values(void);
int		*get_possibilities_for_xy(int x, int y);
void	print_possibilities(void);

/**print.c**/
void	ft_putchar(char c);
int		error(void);
void	print(void);

/**solver.c**/
int		is_solvable(void);
int		**solver(void);

/**tab.c**/
void	set_indices_str(char *str);
void	init(int **tab);
int		is_value(void);

#endif

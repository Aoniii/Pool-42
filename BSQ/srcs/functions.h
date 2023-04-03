/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:29:38 by snourry           #+#    #+#             */
/*   Updated: 2022/01/31 22:29:40 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/**	all include we need **/
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stdio.h>

/**
 * This struct contains width, height and content of map
 * and the different char.
**/

typedef struct s_map
{
	int				**map;
	char			**board;
	int				width;
	int				height;
	char			empty;
	char			full;
	char			obstacle;
}	t_map;

/**
 * This struct stock a location of solving and the value.
**/

typedef struct s_location
{
	int	y;
	int	x;
	int	value;
}	t_location;

/**	ft_check.c **/
int			ft_check_error(void);
int			ft_check_global(char *filename);
int			ft_check_size(char *filename);
int			ft_check_char(char *filename);
int			ft_check_input(char *str);

/**	ft_file.c **/
int			ft_file_is_exist(char *filename);
int			ft_file_get_length(char *filename);
char		*ft_file_get_str(char *filename);
char		**ft_file_get_board(char *filename);
char		**ft_input_get_board(char *str);

/**	ft_map.c **/
t_map		*ft_map_creat(char *filename);
t_map		*ft_map_creat_input(char *str);
void		ft_malloc_map(t_map *map);
void		ft_init_map(t_map *map);

/**	ft_print.c **/
void		ft_print_map(t_map *map);

/**	ft_solver.c **/
int			ft_get_minimun(int i1, int i2, int i3);
void		ft_solve(t_map *map);
t_location	get_solve_location(t_map *map);
void		ft_solve_writer(t_map *map);

/** ft_split.c **/
int			ft_is_charset(char c, char *charset);
int			ft_is_word(char c, char before, char *charset);
int			ft_size_tab(char *str, char *charset);
int			*ft_size_word(char *str, char *charset, int size);
char		**ft_split(char *str, char *charset);

/** ft_string.c **/
int			ft_strlen(char *str);
void		ft_putstr(char *str);
int			ft_atoi(char *str);
void		ft_free_board(char **board);
void		ft_free_map(t_map *map);

#endif

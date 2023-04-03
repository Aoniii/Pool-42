/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Bruno Da Silva <brda-sil@1E4.42angoulem    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 10:48:36 by snourry           #+#    #+#             */
/*   Updated: 2022/01/29 19:38:17 by Bruno Da Si      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

/*	ft_string.c */
int			ft_strlen(char *str);
long long	ft_atol(char *str);
char		*ft_strncat(char *dest, char *src, unsigned int nb);
int			ft_str_is_numeric(char *str);
char		*ft_cut(char *str, char *output);

/*	ft_string2.c */
int			ft_find(char *to_find, int i, char *str);
char		*ft_strstr(char *str, char *to_find);
void		ft_putstr(char *str);

/*	ft_convert.c */
int			ft_is_exist(char *name);
int			ft_get_file_size(char *name);
char		*ft_get_file(char *name);

/*	ft_search.c */
void		ft_search_dico(char *nbr, char *dico, char *output);
int			ft_search_global(char *nbr, char *dico, char *output);
void		ft_search_base(char *nbr, char *dico, char *output);
void		ft_put_three(char *nbr, char *dico, char *output);
void		ft_put_two(char *nbr, char *dico, char *output);

/*	ft_search2.c */
void		ft_search_thousand(char *nbr, char *dico, char *output);
void		ft_search_million(char *nbr, char *dico, char *output);
void		ft_search_billion(char *nbr, char *dico, char *output);

#endif

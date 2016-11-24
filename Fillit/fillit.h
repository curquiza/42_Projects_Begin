/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 12:02:40 by baparis           #+#    #+#             */
/*   Updated: 2016/11/24 19:55:32 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include <stdio.h>

# define SIZE 1

typedef struct	s_list
{
	int				used;
	char			*tetri1d;
	char			**tetri2d;
	struct s_list	*next;
}				t_list;


void				ft_printsolve(char **solve);

// FCT LIBFT
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putendl(char *str);
void				ft_putstr(char *str);
size_t				ft_strlen(char *str);
char				**ft_strsplit(char const *s, char c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strdup(char *s);

// FCT READ
char				*ft_read_and_fill(char *av);

// FCT DE VERIF
int					ft_check_typeofchar(char *file);
int					ft_count_bigblocks(char *file);
int					ft_check_hight(char *file);
int					ft_check_nbblocks(char *file);
int					ft_check_rowlen(char **tab);
int					ft_check_tetriminos(char **tab);
int					ft_check_input(int ac, char **av);

// FCT FICHIER RESOLVE.C
void				ft_lst_pushback(t_list **alst, t_list *new);
t_list				*ft_create_elem(char *tetri1d);
void				ft_fill_lst(t_list **alst, char *file);
int					ft_resolve(char *av);

#endif

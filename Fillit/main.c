/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:28:38 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/30 18:33:29 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_input(int ac, char **av)
{
	char	**tab_file;
	char	*file;

	tab_file = NULL;
	if (ac != 2)
	{
		ft_putendl("usage: ./fillit file");
		exit(0);
	}
	file = ft_read_and_fill(av[1]);
	if (file == NULL)
		return (0);
	if (ft_check_typeofchar(file) == 0 || ft_count_bigblocks(file) == 0
			|| ft_count_bigblocks(file) > 26 || ft_check_hight(file) == 0
			|| ft_check_nbblocks(file) == 0)
		return (0);
	tab_file = ft_strsplit(file, '\n');
	if (ft_check_rowlen(tab_file) == 0 || ft_check_tetriminos(tab_file) == 0)
		return (0);
	return (1);
}

char	**ft_taballoc(int i)
{
	char	**tab;
	int		j;
	int		k;

	k = 0;
	j = 0;
	if (!(tab = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		k = 2;
		tab[j] = ft_strnew(i + 2);
		tab[j][0] = '?';
		tab[j][1] = '?';
		while (k < i + 1)
			tab[j][k++] = '.';
		j++;
	}
	i = 0;
	j--;
	while (i < k)
		tab[j][i++] = '?';
	tab[++j] = 0;
	return (tab);
}

void	ft_print_tab(char **tab)
{
	while (*tab && *(*tab + 3) != '?')
	{
		ft_putendl(*tab + 2);
		tab++;
	}
}

int		main(int ac, char **av)
{
	t_list	*lst;
	char	**grid;
	int		i;

	i = 3;
	if (ft_check_input(ac, av) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	lst = ft_fill_lst(av[1]);
	if (!(grid = ft_taballoc(i++)))
		return (0);
	while (!(ft_algo(lst, grid)))
		if ((grid = ft_taballoc(i++)) == NULL)
			return (0);
	ft_print_tab(grid);
	return (0);
}

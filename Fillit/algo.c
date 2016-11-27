/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baparis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:44:30 by baparis           #+#    #+#             */
/*   Updated: 2016/11/25 19:21:00 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*int	ft_check_and_place(char **endgrid, t_list lst, int i, int j)
{
	int	k;

	k = 0;
	while (endgrid[k])
		k++;
	if (k > 4)
		return (1);
	(void)lst;
	(void)i;
	(void)j;
	return (0);
}*/

// CLEM
int		ft_check_case(char **endgrid, int i, int j)
{
	if (endgrid[i][j] == '.')
		return (1);
	return (0);
}

int		ft_check_a_position(char **endgrid, t_list lst, int i, int j)
{
	int		k;
	int		tmp_k;

	k = 0;
	if (ft_check_case(endgrid, i, j) == 0)
		return (0);
	endgrid[i][j] = lst.letter;
	while (*(lst.tetri1d) != '#')
		(lst.tetri1d)++;
	tmp_k = k;
	while (*(lst.tetri1d))
	{
		if (*(lst.tetri1d) == '#')
		{
			if (ft_check_case(endgrid, i + (k / 4 - tmp_k / 4), j + (k % 4 - tmp_k % 4) == 0))
				return (0);
			endgrid[i + (k / 4 - tmp_k / 4)][j + (k % 4 - tmp_k % 4)] = lst.letter;
		}
		if (*(lst.tetri1d) != '\n')
			k++;
		(lst.tetri1d)++;
	}
	return (1);
}

int		ft_check_and_place(char **endgrid, t_list lst, int i, int j)
{
	if (endgrid[i + 2] == 0 && endgrid[i][j] == '\0')
		return (0);
	else
	{
		j++;
		if (endgrid[i][j] == '\0')
		{
			j = 1;
			i++;
		}
		if (ft_check_and_place(endgrid, lst, i, j) == 1)
			return (1);
	}
	return (0);
}


/*
 * Efface les lettres ecrite dans la grid final quand cela n'est pas valide
 */

void	ft_erase(t_list *lst, char **endgrid)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	lst->used = 0;
	while (endgrid[j])
	{
		i = 0;
		while (endgrid[j][i])
		{
			if (endgrid[j][i] == lst->letter)
				endgrid[j][i] = '.';
			i++;
		}
		j++;
	}
}

int		ft_algo(t_list *lst, char **endgrid)
{
	t_list *tmp;

	tmp = lst;
	while (tmp && tmp->used == 1)
		tmp = tmp->next;
	if (!(tmp))
		return (1);
	while (tmp)
	{
		while (tmp->used == 1 && tmp)
			tmp = tmp->next;
		if (ft_check_and_place(endgrid, *tmp, 0, 1))
		{
			tmp->used = 1;
			if (!(ft_algo(lst, endgrid)))
				ft_erase(tmp, endgrid);
			else
				return (1);
		}
		if (tmp)
			tmp = tmp->next;
	}
	return (0);
}

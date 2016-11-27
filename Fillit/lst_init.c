/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:10:28 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/25 18:10:38 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// Pas possible de prendre celui de la libft car pas la meme structure
void		ft_lst_pushback(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst == NULL)
		return ;
	tmp = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

// Creer un maillon
t_list		*ft_create_elem(char *tetri1d, int num)
{
	t_list	*new;

	if (tetri1d == NULL)
		return (NULL);
	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (NULL);
	new->used = 0;
	new->letter = 'A' + num;
	new->tetri1d = ft_strdup(tetri1d);
	new->tetri2d = ft_strsplit(new->tetri1d, '\n');
	new->next = NULL;
	return (new);
}

// Remplit la liste chainee = ajoute des maillons en fonction du nombre de grands blocks
t_list		*ft_fill_lst(char *av)
{
	int		cpt;
	t_list	*lst;
	char	*file;

	lst = NULL;
	file = ft_read_and_fill(av);
	cpt = 0;
	while (*file)
	{
		ft_lst_pushback(&lst, ft_create_elem(ft_strsub(file, 0, 20), cpt));
		file = file + 20;
		if (*file)
			file++;
		cpt++;
	}
	return (lst);
}

// POUR TEST : affiche les composants de chaque maillon
/*void		ft_print_list(t_list *lst)
{
	while (lst)
	{
		printf("used : %d\n", lst->used);
		printf("letter : %c\n", lst->letter);
		printf("tetri1d :\n%s", lst->tetri1d);
		printf("tetri2d :\n");
		while (*(lst->tetri2d))
		{
			printf("%s\n", *(lst->tetri2d));
			(lst->tetri2d)++;
		}
		printf("\n");
		lst = lst->next;
	}
}*/
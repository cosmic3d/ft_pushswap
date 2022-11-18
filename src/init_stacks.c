/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:12:54 by jenavarr          #+#    #+#             */
/*   Updated: 2022/11/18 21:29:23 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	ft_init_a(t_stack *a, int len, char **s)
{
	t_node	*node;
	t_node	*tmp;

	a->first = NULL;
	a->last = NULL;
	a->len = -1;
	while (++a->len < len - 1)
	{
		node = ft_newnode(ft_atoi(s[a->len + 1]), a->len);
		if (!a->first)
		{
			a->first = node;
			a->last = node;
		}
		else
		{
			tmp = a->last;
			a->last = node;
			tmp->next = a->last;
			a->last->back = tmp;
		}
	}
}

void	ft_init_b(t_stack *b)
{
	b->first = NULL;
	b->last = NULL;
	b->len = 0;
}

t_node	*ft_newnode(int nbr, int ind)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = nbr;
	node->index = ind;
	node->back = NULL;
	node->next = NULL;
	return (node);
}
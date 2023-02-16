/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:12:54 by jenavarr          #+#    #+#             */
/*   Updated: 2023/02/16 19:32:22 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/checker.h"

int	ft_init_a(t_stack *a, int len, char **s)
{
	t_node	*node;
	t_node	*tmp;

	ft_stack_values(a, -1, 'a');
	while (++a->len < len - 1)
	{
		node = ft_newnode(ft_atoi(s[a->len + 1]), a->len);
		if (!node)
			return (-1);
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
	return (0);
}

int	ft_init_b(t_stack *b)
{
	return (ft_stack_values(b, 0, 'b'));
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

int	ft_stack_values(t_stack *stack, int len, char id)
{
	stack->first = NULL;
	stack->last = NULL;
	stack->len = len;
	stack->id = id;
	return (0);
}

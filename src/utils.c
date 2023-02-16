/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:26:47 by jenavarr          #+#    #+#             */
/*   Updated: 2023/02/16 16:26:44 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	empty_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack->first)
	{
		tmp = stack->first->next;
		free(stack->first);
		stack->first = tmp;
	}
	stack = NULL;
	return ;
}

int	empty_stacks(t_stack *a, t_stack *b)
{
	empty_stack(a);
	empty_stack(b);
	return (0);
}

void	first_last(t_node *node_a, t_stack *a, t_node *node_b, t_stack *b)
{
	if (a && a->len == 1 && a->first)
	{
		a->first = node_a;
		a->last = node_a;
		node_a->back = NULL;
		node_a->next = NULL;
	}
	if (b && b->len == 1 && b->first)
	{
		b->first = node_b;
		b->last = node_b;
		node_b->back = NULL;
		node_b->next = NULL;
	}
	return ;
}

int	ft_error(t_stack *a, t_stack *b)
{
	empty_stacks(a, b);
	write(2, "Error\n", 6);
	exit(1);
	return (0);
}

int	ft_is_ordered(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return (1);
	if (stack->len < 2)
		return (1);
	tmp = stack->first;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

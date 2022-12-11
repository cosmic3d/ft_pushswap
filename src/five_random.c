/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenavarr <jenavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:21:05 by jenavarr          #+#    #+#             */
/*   Updated: 2022/12/11 20:50:50 by jenavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdrs/pushswap.h"

void	three_random(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		if (a->first->val > a->last->val)
			return (swap_a(a, b));
	if (a->last->val > a->first->val && a->last->val > a->first->next->val)
		return (swap_a(a, b));
	if (a->last->back->val < a->last->val && a->last->val < a->first->val)
		return (reverse_rotate_a(a, b));
	if (a->first->val > a->last->back->val && a->last->back->val > a->last->val)
	{
		swap_a(a, b);
		return (rotate_a(a, b));
	}
	if (a->last->back->val > a->last->val && a->last->back->val > a->first->val)
	{
		if (a->first->val < a->last->val)
		{
			swap_a(a, b);
			return (reverse_rotate_a(a, b));
		}
	}
	if (a->last->val < a->first->val && a->first->val < a->last->back->val)
		return (rotate_a(a, b));
}

void	five_random(t_stack *a, t_stack *b)
{
	if (a->len == 5)
		push_b(a, b);
	push_b(a, b);
	three_random(a, b);
}

int	check_smaller(t_stack *stack, int exclude)
{
	t_node	*smaller;
	t_node	*tmp;

	tmp = stack->first;
	smaller = stack->first;
	while (tmp->next)
	{
		if (tmp->next->val < smaller->val && tmp->next->index != exclude)
			smaller = tmp->next;
		tmp = tmp->next;
	}
	return (smaller->index);
}
